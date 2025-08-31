#include "object.h"

namespace renderer {

Object::Object(std::vector<Triangle>&& triangles) : triangles_(std::move(triangles)) {
}

void Object::addTriangle(const Triangle& triangle) {
  triangles_.push_back(triangle);
}

void Object::addTriangle(Triangle&& triangle) {
  triangles_.push_back(std::move(triangle));
}

const std::vector<Triangle>& Object::triangles() const {
  return triangles_;
}

}  // namespace renderer
