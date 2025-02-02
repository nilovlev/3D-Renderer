#pragma once

#include "screen.h"
#include "triangle.h"

namespace renderer {

class Renderer {
 private:
  Screen& screen_;

 public:
  Renderer(Screen& screen);
  void rasterizeTriangle(const Triangle& triangle);
};

}  // namespace renderer
