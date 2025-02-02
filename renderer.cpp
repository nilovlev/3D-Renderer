#include "renderer.h"

namespace renderer {

Renderer::Renderer(Screen& screen) : screen_(screen) {
}

double triangleSignedArea(double ax, double ay, double bx, double by, double cx, double cy) {
  return ((bx - ax) * (cy - ay) - (by - ay) * (cx - ax)) / 2;
}

bool isInsideTriangle(double x, double y, const Triangle& triangle) {
  double abv = triangleSignedArea(triangle.a.x(), triangle.a.y(), triangle.b.x(), triangle.b.y(), x, y);
  double bcv = triangleSignedArea(triangle.b.x(), triangle.b.y(), triangle.c.x(), triangle.c.y(), x, y);
  double cav = triangleSignedArea(triangle.c.x(), triangle.c.y(), triangle.a.x(), triangle.a.y(), x, y);
  return (abv >= 0 && bcv >= 0 && cav >= 0);
}

void Renderer::rasterizeTriangle(const Triangle& triangle) {

  int minX = std::min(triangle.a.x(), std::min(triangle.b.x(), triangle.c.x()));
  int minY = std::min(triangle.a.y(), std::min(triangle.b.y(), triangle.c.y()));
  int maxX = std::max(triangle.a.x(), std::max(triangle.b.x(), triangle.c.x()));
  int maxY = std::max(triangle.a.y(), std::max(triangle.b.y(), triangle.c.y()));

  for (uint32_t x = minX; x < maxX; ++x) {
    for (uint32_t y = minY; y < maxY; ++y) {
      if (isInsideTriangle(x, y, triangle)) {
        screen_.setPixel(x, y, sf::Color(255, 255, 255));
      }
    }
  }

}

}  // namespace renderer
