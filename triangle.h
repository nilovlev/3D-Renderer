#pragma once

#include "linalg.h"
#include "color.h"

namespace renderer {

struct Triangle {
  Vector3 a, b, c;
  Vector3 normalA, normalB, normalC;
  Color color;
};

}  // namespace renderer
