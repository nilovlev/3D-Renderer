#include "object.h"

namespace renderer {

Object::Object(const std::vector<Triangle>& triangles) : triangles_(triangles) {
}

void Object::addTriangle(const Triangle& triangle) {
  triangles_.push_back(triangle);
}

const std::vector<Triangle>& Object::getTriangles() const {
  return triangles_;
}

}  // namespace renderer
