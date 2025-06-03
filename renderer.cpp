#include "renderer.h"

#include <cstdint>

namespace renderer {

float Renderer::triangleSignedArea(const Vector2& a, const Vector2& b, const Vector2& c) const {
  return ((b - a).x() * (c - a).y() - (b - a).y() * (c - a).x()) / 2;
}

int Renderer::toDiscreteFloor(float coord) {
  return static_cast<int>(std::floor(coord));
}

int Renderer::toDiscreteCeil(float coord) {
  return static_cast<int>(std::ceil(coord));
}

Screen Renderer::rasterizeTriangle(const Triangle& triangle, Screen&& screen,
                                   const Matrix4& viewMatrix) const {
  Vector2 a2(triangle.a.x(), triangle.a.y());
  Vector2 b2(triangle.b.x(), triangle.b.y());
  Vector2 c2(triangle.c.x(), triangle.c.y());

  int minX = std::min(toDiscreteFloor(triangle.a.x()),
                      std::min(toDiscreteFloor(triangle.b.x()), toDiscreteFloor(triangle.c.x())));
  int minY = std::min(toDiscreteFloor(triangle.a.y()),
                      std::min(toDiscreteFloor(triangle.b.y()), toDiscreteFloor(triangle.c.y())));
  int maxX = std::max(toDiscreteCeil(triangle.a.x()),
                      std::max(toDiscreteCeil(triangle.b.x()), toDiscreteCeil(triangle.c.x())));
  int maxY = std::max(toDiscreteCeil(triangle.a.y()),
                      std::max(toDiscreteCeil(triangle.b.y()), toDiscreteCeil(triangle.c.y())));

  Vector4 lightView(0, 0, -1, 0);
  Vector4 lightWorld4 = viewMatrix.inverse() * lightView;
  Vector3 light = lightWorld4.head<3>().normalized();
  float area = triangleSignedArea(a2, b2, c2);
  if (area == 0.0f) return std::move(screen);

  for (uint32_t x = minX; x <= maxX; ++x) {
    for (uint32_t y = minY; y <= maxY; ++y) {
      Vector2 p(x, y);
      float w0 = triangleSignedArea(b2, c2, p) / area;
      float w1 = triangleSignedArea(c2, a2, p) / area;
      float w2 = triangleSignedArea(a2, b2, p) / area;

      if (w0 >= 0 && w1 >= 0 && w2 >= 0) {
        float z = w0 * triangle.a.z() + w1 * triangle.b.z() + w2 * triangle.c.z();

        Vector3 normal =
            (w0 * triangle.normalA + w1 * triangle.normalB + w2 * triangle.normalC).normalized();
        float brightness = std::max(0.0f, normal.dot(light));

        uint8_t r = static_cast<uint8_t>(triangle.color.r * brightness);
        uint8_t g = static_cast<uint8_t>(triangle.color.g * brightness);
        uint8_t b = static_cast<uint8_t>(triangle.color.b * brightness);

        screen.setPixel(x, y, r, g, b, triangle.color.a, z);
      }
    }
  }

  return std::move(screen);
}

Triangle Renderer::projectTriangle(const Triangle& triangle, const Matrix4& vp, int screenWidth,
                                   int screenHeight) const {
  auto project = [&](const Vector3& v) -> Vector3 {
    Vector4 vWorld(v.x(), v.y(), v.z(), 1.0f);
    Vector4 vClip = vp * vWorld;

    if (vClip.w() != 0.0f) vClip /= vClip.w();

    float x = (vClip.x() + 1.0f) / 2 * screenWidth;
    float y = (1.0f - (vClip.y() + 1.0f) / 2) * screenHeight;
    float z = 1.0f - (vClip.z() + 1.0f) / 2;

    return Vector3(x, y, z);
  };

  Triangle projected;
  projected.a = project(triangle.a);
  projected.b = project(triangle.b);
  projected.c = project(triangle.c);
  projected.normalA = triangle.normalA;
  projected.normalB = triangle.normalB;
  projected.normalC = triangle.normalC;
  projected.color = triangle.color;
  return projected;
}

Screen Renderer::render(const World& world, Screen&& screen, const Camera& camera) const {
  Matrix4 vp = camera.viewProjectionMatrix();
  Matrix4 viewMatrix = camera.viewMatrix();
  for (const auto& object : world.objects()) {
    for (const auto& triangle : object.triangles()) {
      Triangle projectedTriangle = projectTriangle(triangle, vp, screen.width(), screen.height());
      screen = rasterizeTriangle(projectedTriangle, std::move(screen), viewMatrix);
    }
  }
  return std::move(screen);
}

}  // namespace renderer
