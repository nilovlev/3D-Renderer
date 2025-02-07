#pragma once

#include "screen.h"
#include "triangle.h"
#include "world.h"

namespace renderer {

class Renderer {
 private:
  double triangleSignedArea(double ax, double ay, double bx, double by, double cx, double cy) const;
  bool isInsideTriangle(double x, double y, const Triangle& triangle) const;
  void rasterizeTriangle(const Triangle& triangle, Screen& screen);

 public:
  Renderer() = default;
  void render(World& world, Screen& screen);
};

}  // namespace renderer
