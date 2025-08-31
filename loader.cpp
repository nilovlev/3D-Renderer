#include "loader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace renderer {

Object Loader::load(const std::string& fileName) {
  std::ifstream file(fileName);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + fileName);
  }

  std::vector<Eigen::Vector3f> vertices;
  std::vector<Triangle> triangles;

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string type;

    iss >> type;
    if (type == "v") {
      float x, y, z;
      iss >> x >> y >> z;
      vertices.emplace_back(x, y, z);
    } else if (type == "f") {
      int vi[3];
      if (line.find("/") != std::string::npos) {
        std::replace(line.begin(), line.end(), '/', ' ');
      }

      std::istringstream faceStream(line);
      std::string _;
      faceStream >> _;
      faceStream >> vi[0] >> vi[1] >> vi[2];

      Triangle triangle;
      triangle.a = vertices[vi[0] - 1];
      triangle.b = vertices[vi[1] - 1];
      triangle.c = vertices[vi[2] - 1];
      triangle.color = Colors::White;

      Vector3 edge1 = triangle.b - triangle.a;
      Vector3 edge2 = triangle.c - triangle.a;
      Vector3 faceNormal = edge1.cross(edge2).normalized();
      triangle.normalA = faceNormal;
      triangle.normalB = faceNormal;
      triangle.normalC = faceNormal;

      triangles.push_back(triangle);
    }
  }

  return Object(std::move(triangles));
}

}  // namespace renderer
