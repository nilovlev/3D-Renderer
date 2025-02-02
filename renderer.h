#pragma once

#include "screen.h"
#include "triangle.h"

namespace renderer {

class Renderer {
 private:
  Screen& screen_;
  double triangleSignedArea(double ax, double ay, double bx, double by, double cx, double cy);
  bool isInsideTriangle(double x, double y, const Triangle& triangle);

 public:
  Renderer(Screen& screen);
  void rasterizeTriangle(const Triangle& triangle);
};

}  // namespace renderer
