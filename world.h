#pragma once

#include "object.h"

#include <vector>

namespace renderer {

class World {
 private:
  std::vector<Object> objects_;

 public:
  World() = default;
  void addObject(const Object& object);
  void addObject(Object&& object);
  const std::vector<Object>& objects() const;
};

}  // namespace renderer
