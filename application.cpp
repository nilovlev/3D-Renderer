#include "application.h"

#include <SFML/Graphics.hpp>

#include "triangle.h"

namespace renderer {

Application::Application() : screen_(Screen()), renderer_(screen_) {
}

void Application::run() {
  Triangle testTriangle = {{100, 100, 0}, {400, 200, 0}, {200, 300, 0}};

  renderer_.rasterizeTriangle(testTriangle);
  screen_.show();
}

}  // namespace renderer
