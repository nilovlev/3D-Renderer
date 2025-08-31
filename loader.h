#pragma once

#include <string>

#include "object.h"

namespace renderer {

class Loader {
 public:
  static Object load(const std::string &fileName);
};

}  // namespace renderer
