#pragma once

#include <Eigen/Dense>

namespace renderer {

using Vertex = Eigen::Vector3f;

struct Triangle {
  Vertex a;
  Vertex b;
  Vertex c;
};

}  // namespace renderer
