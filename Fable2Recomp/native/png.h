// Minimal PNG writer (stored/uncompressed deflate) for debug output of the native renderer.
#pragma once

#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

namespace native {

inline bool WritePng(const std::string& path, const uint8_t* rgba, uint32_t width, uint32_t height) {
  auto crc_table = [] {
    static uint32_t t[256];
    for (uint32_t n = 0; n < 256; ++n) {
      uint32_t c = n;
      for (int k = 0; k < 8; ++k) c = (c & 1) ? 0xEDB88320u ^ (c >> 1) : c >> 1;
      t[n] = c;
    }
    return t;
  }();
  auto crc = [&](const uint8_t* p, size_t n, uint32_t c = 0xFFFFFFFFu) {
    for (size_t i = 0; i < n; ++i) c = crc_table[(c ^ p[i]) & 0xFF] ^ (c >> 8);
    return c;
  };
  std::vector<uint8_t> raw;
  raw.reserve(size_t(height) * (width * 4 + 1));
  for (uint32_t y = 0; y < height; ++y) {
    raw.push_back(0);
    raw.insert(raw.end(), rgba + size_t(y) * width * 4, rgba + size_t(y + 1) * width * 4);
  }
  std::vector<uint8_t> z = {0x78, 0x01};
  uint32_t a = 1, b = 0;
  for (uint8_t v : raw) {
    a = (a + v) % 65521;
    b = (b + a) % 65521;
  }
  for (size_t pos = 0; pos < raw.size() || pos == 0;) {
    size_t n = std::min<size_t>(65535, raw.size() - pos);
    bool last = pos + n >= raw.size();
    z.push_back(last ? 1 : 0);
    z.push_back(uint8_t(n));
    z.push_back(uint8_t(n >> 8));
    z.push_back(uint8_t(~n));
    z.push_back(uint8_t(~n >> 8));
    z.insert(z.end(), raw.begin() + pos, raw.begin() + pos + n);
    pos += n;
    if (last) break;
  }
  uint32_t adler = (b << 16) | a;
  for (int i = 3; i >= 0; --i) z.push_back(uint8_t(adler >> (i * 8)));
  FILE* f = std::fopen(path.c_str(), "wb");
  if (!f) return false;
  auto chunk = [&](const char* type, const std::vector<uint8_t>& data) {
    uint8_t len[4] = {uint8_t(data.size() >> 24), uint8_t(data.size() >> 16), uint8_t(data.size() >> 8),
                      uint8_t(data.size())};
    std::fwrite(len, 1, 4, f);
    std::vector<uint8_t> td(type, type + 4);
    td.insert(td.end(), data.begin(), data.end());
    std::fwrite(td.data(), 1, td.size(), f);
    uint32_t c = crc(td.data(), td.size()) ^ 0xFFFFFFFFu;
    uint8_t cb[4] = {uint8_t(c >> 24), uint8_t(c >> 16), uint8_t(c >> 8), uint8_t(c)};
    std::fwrite(cb, 1, 4, f);
  };
  static const uint8_t sig[8] = {0x89, 'P', 'N', 'G', 0x0D, 0x0A, 0x1A, 0x0A};
  std::fwrite(sig, 1, 8, f);
  std::vector<uint8_t> ihdr = {uint8_t(width >> 24), uint8_t(width >> 16), uint8_t(width >> 8), uint8_t(width),
                               uint8_t(height >> 24), uint8_t(height >> 16), uint8_t(height >> 8), uint8_t(height),
                               8, 6, 0, 0, 0};
  chunk("IHDR", ihdr);
  chunk("IDAT", z);
  chunk("IEND", {});
  std::fclose(f);
  return true;
}

}  // namespace native
