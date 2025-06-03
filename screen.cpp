#include "screen.h"

#include <iostream>
#include <limits>

namespace renderer {

Screen::Screen(int width, int height)
    : width_(width),
      height_(height),
      pixels_(width * height * 4, 0),
      zBuffer_(width_ * height_, std::numeric_limits<float>::infinity()) {
}

void Screen::setPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a, float z) {
  if (x >= width_ || y >= height_) return;

  int index = y * width_ + x;
  if (z < zBuffer_[index]) {
    zBuffer_[index] = z;
    int i = index * 4;
    pixels_[i + 0] = r;
    pixels_[i + 1] = g;
    pixels_[i + 2] = b;
    pixels_[i + 3] = a;
  }
}

void Screen::clear() {
  std::fill(pixels_.begin(), pixels_.end(), 0);
  std::fill(zBuffer_.begin(), zBuffer_.end(), std::numeric_limits<float>::infinity());
}

int Screen::width() const {
  return width_;
}

int Screen::height() const {
  return height_;
}

const std::vector<uint8_t>& Screen::pixels() const {
  return pixels_;
}

}  // namespace renderer
