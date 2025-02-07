#pragma once

#include <vector>

#include "object.h"

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
