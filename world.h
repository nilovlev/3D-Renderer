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
  const std::vector<Object>& getObjects() const;
};

}  // namespace renderer
