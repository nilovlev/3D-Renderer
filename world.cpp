#include "world.h"

namespace renderer {

void World::addObject(const Object& object) {
  objects_.push_back(object);
}

const std::vector<Object>& World::getObjects() const {
  return objects_;
}

}  // namespace renderer
