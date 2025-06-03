#pragma once

#include <cstdint>

namespace renderer {

struct Color {
  uint8_t r = 255;
  uint8_t g = 255;
  uint8_t b = 255;
  uint8_t a = 255;
};

namespace Colors {

constexpr Color White = {255, 255, 255, 255};
constexpr Color Black = {0, 0, 0, 255};
constexpr Color Red = {255, 0, 0, 255};
constexpr Color Green = {0, 255, 0, 255};
constexpr Color Blue = {0, 0, 255, 255};

}  // namespace Colors

}  // namespace renderer
