#include "capture.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>

namespace replay {

namespace {

#pragma pack(push, 1)
struct EventHeader {
  uint32_t magic, fn, phase, seq;
  uint32_t r[8];
  double f1;
  uint32_t sp, frame, blob_count, reserved;
};
struct BlobHeader {
  uint32_t kind, addr, size, reserved;
};
#pragma pack(pop)
static_assert(sizeof(EventHeader) == 72, "EventHeader layout");

}  // namespace

bool Capture::Load(const std::filesystem::path& dir, std::string* error) {
  physical_.assign(0x20000000, 0);
  device_.assign(kDeviceSize, 0);

  std::ifstream index(dir / "memory_index.txt");
  std::ifstream mem(dir / "memory.bin", std::ios::binary);
  if (!index || !mem) {
    *error = "memory_index.txt / memory.bin not found in " + dir.string();
    return false;
  }
  std::string line;
  while (std::getline(index, line)) {
    if (line.empty() || line[0] == '#') continue;
    std::istringstream ls(line);
    char space;
    std::string a, n, o;
    ls >> space >> a >> n >> o;
    uint64_t addr = std::stoull(a, nullptr, 16), size = std::stoull(n, nullptr, 16),
             off = std::stoull(o, nullptr, 16);
    mem.seekg(std::streamoff(off));
    if (space == 'P') {
      if (addr + size > physical_.size()) size = physical_.size() - addr;
      mem.read(reinterpret_cast<char*>(physical_.data() + addr), std::streamsize(size));
    } else {
      Region r{uint32_t(addr), std::vector<uint8_t>(size)};
      mem.read(reinterpret_cast<char*>(r.data.data()), std::streamsize(size));
      virtual_.push_back(std::move(r));
    }
  }
  std::sort(virtual_.begin(), virtual_.end(), [](const Region& x, const Region& y) { return x.addr < y.addr; });

  std::ifstream ev(dir / "events.bin", std::ios::binary);
  if (!ev) {
    *error = "events.bin not found";
    return false;
  }
  EventHeader h;
  while (ev.read(reinterpret_cast<char*>(&h), sizeof(h))) {
    if (h.magic != 0x31545645) {
      *error = "bad event magic";
      return false;
    }
    Event e;
    e.fn = h.fn;
    e.phase = h.phase;
    e.seq = h.seq;
    std::memcpy(e.r, h.r, sizeof(e.r));
    e.f1 = h.f1;
    e.sp = h.sp;
    e.frame = h.frame;
    e.blobs.resize(h.blob_count);
    for (auto& b : e.blobs) {
      BlobHeader bh;
      ev.read(reinterpret_cast<char*>(&bh), sizeof(bh));
      b.kind = bh.kind;
      b.addr = bh.addr;
      b.data.resize(bh.size);
      ev.read(reinterpret_cast<char*>(b.data.data()), bh.size);
    }
    if (!device_address_ && e.phase == 0) device_address_ = e.r[0];
    events_.push_back(std::move(e));
  }
  return true;
}

void Capture::Apply(const Event& e) {
  for (const Blob& b : e.blobs) {
    switch (b.kind) {
      case kBlobDevice:
        if (b.addr + b.data.size() <= device_.size()) std::memcpy(device_.data() + b.addr, b.data.data(), b.data.size());
        break;
      case kBlobPhysical:
        if (b.addr + b.data.size() <= physical_.size())
          std::memcpy(physical_.data() + b.addr, b.data.data(), b.data.size());
        break;
      case kBlobVirtual:
      case kBlobUpData:
        WriteVirtual(b.addr, b.data.data(), uint32_t(b.data.size()));
        break;
      default:
        break;
    }
  }
  // Keep the device copy in guest memory coherent too (objects read through Virtual()).
  if (device_address_) WriteVirtual(device_address_, device_.data(), kDeviceSize);
}

const uint8_t* Capture::Physical(uint32_t addr, uint32_t size) const {
  addr &= 0x1FFFFFFF;
  if (uint64_t(addr) + size > physical_.size()) return nullptr;
  return physical_.data() + addr;
}

const uint8_t* Capture::Virtual(uint32_t addr, uint32_t size) const {
  if (addr >= 0xA0000000) return Physical(VirtualToPhysical(addr), size);
  return const_cast<Capture*>(this)->VirtualMutable(addr, size);
}

uint8_t* Capture::VirtualMutable(uint32_t addr, uint32_t size) {
  auto it = std::upper_bound(virtual_.begin(), virtual_.end(), addr,
                             [](uint32_t a, const Region& r) { return a < r.addr; });
  if (it == virtual_.begin()) return nullptr;
  --it;
  if (uint64_t(addr) + size > uint64_t(it->addr) + it->data.size()) return nullptr;
  return it->data.data() + (addr - it->addr);
}

void Capture::WriteVirtual(uint32_t addr, const uint8_t* src, uint32_t size) {
  if (addr >= 0xA0000000) {
    uint32_t p = VirtualToPhysical(addr);
    if (uint64_t(p) + size <= physical_.size()) std::memcpy(physical_.data() + p, src, size);
    return;
  }
  if (uint8_t* dst = VirtualMutable(addr, size)) {
    std::memcpy(dst, src, size);
    return;
  }
  // Not inside a dumped region (allocated during the frame): keep as its own region.
  Region r{addr, std::vector<uint8_t>(src, src + size)};
  auto it = std::upper_bound(virtual_.begin(), virtual_.end(), addr,
                             [](uint32_t a, const Region& x) { return a < x.addr; });
  virtual_.insert(it, std::move(r));
}

}  // namespace replay
