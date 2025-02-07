#pragma once

#include <vector>

#include "triangle.h"

namespace renderer {

class Object {
 private:
  std::vector<Triangle> triangles_;

 public:
  Object() = default;
  Object(const std::vector<Triangle>& triangles);
  void addTriangle(const Triangle& triangle);
  const std::vector<Triangle>& getTriangles() const;
};

}  // namespace renderer
