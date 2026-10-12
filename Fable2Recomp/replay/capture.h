// Loader for D3D frame captures written by src/d3d_capture.cpp (F9 in game).
// Rebuilds guest memory and the D3D device object event by event, so a replayer can walk a
// captured frame in call order.
#pragma once

#include <cstdint>
#include <filesystem>
#include <string>
#include <vector>

namespace replay {

enum BlobKind : uint32_t {
  kBlobDevice = 1,    // addr = device offset
  kBlobVirtual = 2,   // guest virtual range
  kBlobPhysical = 3,  // guest physical range
  kBlobCommands = 4,  // command bytes the call wrote (reference only)
  kBlobUpData = 5,    // data written into Begin*Vertices space (virtual)
  kBlobGapCommands = 6,
};

struct Blob {
  uint32_t kind = 0;
  uint32_t addr = 0;
  std::vector<uint8_t> data;
};

struct Event {
  uint32_t fn = 0;     // d3dhooks::Fn
  uint32_t phase = 0;  // 0 before the original ran, 1 after
  uint32_t seq = 0;
  uint32_t r[8] = {};  // r3..r10 (after: r[0] = return value)
  double f1 = 0;
  uint32_t sp = 0;
  uint32_t frame = 0;
  std::vector<Blob> blobs;
};

inline uint32_t BE32(const uint8_t* p) {
  return (uint32_t(p[0]) << 24) | (uint32_t(p[1]) << 16) | (uint32_t(p[2]) << 8) | p[3];
}

class Capture {
 public:
  static constexpr uint32_t kDeviceSize = 16384;

  bool Load(const std::filesystem::path& dir, std::string* error);

  const std::vector<Event>& events() const { return events_; }

  // Applies an event's memory/device blobs (call in order, before handling the event).
  void Apply(const Event& e);

  // Guest memory as of the last Apply. Returns nullptr when the range is not captured.
  const uint8_t* Physical(uint32_t addr, uint32_t size) const;
  const uint8_t* Virtual(uint32_t addr, uint32_t size) const;
  uint32_t Load32(uint32_t vaddr) const {
    const uint8_t* p = Virtual(vaddr, 4);
    return p ? BE32(p) : 0;
  }
  // Physical address for a guest virtual address in the 0xA0000000+ physical views.
  static uint32_t VirtualToPhysical(uint32_t vaddr) {
    return (vaddr & 0x1FFFFFFF) + (vaddr >= 0xE0000000 ? 0x1000 : 0);
  }

  const uint8_t* device() const { return device_.data(); }
  uint32_t device_address() const { return device_address_; }
  uint32_t dev32(uint32_t offset) const { return BE32(device_.data() + offset); }

 private:
  struct Region {
    uint32_t addr;
    std::vector<uint8_t> data;
  };
  uint8_t* VirtualMutable(uint32_t addr, uint32_t size);
  void WriteVirtual(uint32_t addr, const uint8_t* src, uint32_t size);

  std::vector<Event> events_;
  std::vector<uint8_t> physical_;   // 512 MB
  std::vector<Region> virtual_;     // sorted by addr
  std::vector<uint8_t> device_;
  uint32_t device_address_ = 0;
};

}  // namespace replay
