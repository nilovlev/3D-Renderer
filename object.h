#pragma once

#include <vector>

#include "triangle.h"

namespace renderer {

class Object {
 private:
  std::vector<Triangle> triangles_;

 public:
  Object() = default;
  Object(std::vector<Triangle>&& triangles);
  void addTriangle(const Triangle& triangle);
  void addTriangle(Triangle&& triangle);
  const std::vector<Triangle>& triangles() const;
};

}  // namespace renderer
