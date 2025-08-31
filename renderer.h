#pragma once

#include "camera.h"
#include "linalg.h"
#include "screen.h"
#include "triangle.h"
#include "world.h"

namespace renderer {

class Renderer {
 private:
  float triangleSignedArea(const Vector2& a, const Vector2& b, const Vector2& c) const;
  static int toDiscreteFloor(float coord);
  static int toDiscreteCeil(float coord);
  Screen rasterizeTriangle(const Triangle& triangle, Screen&& screen, const Vector3& light) const;
  Triangle projectTriangle(const Triangle& triangle, const Matrix4& vp, int screenWidth,
                           int screenHeight) const;

 public:
  Renderer() = default;
  Screen render(const World& world, Screen&& screen, const Camera& camera) const;
};

}  // namespace renderer
