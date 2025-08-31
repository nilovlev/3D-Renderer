#pragma once

#include <cstdint>
#include <vector>

namespace renderer {

class Screen {
 private:
  int width_;
  int height_;
  std::vector<uint8_t> pixels_;
  std::vector<float> zBuffer_;

 public:
  Screen(int width, int height);
  void setPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a, float z);
  void clear();
  int width() const;
  int height() const;
  const std::vector<uint8_t>& pixels() const;
};

}  // namespace renderer
