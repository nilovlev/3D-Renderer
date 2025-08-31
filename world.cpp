#include "world.h"

namespace renderer {

void World::addObject(const Object& object) {
  objects_.push_back(object);
}

void World::addObject(Object&& object) {
  objects_.push_back(std::move(object));
}

const std::vector<Object>& World::objects() const {
  return objects_;
}

}  // namespace renderer
