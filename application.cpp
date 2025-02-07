#include "application.h"
#include "object.h"
#include "triangle.h"

#include <SFML/Graphics.hpp>

namespace renderer {

void Application::run() {
  const Triangle testTriangle = {{100, 100, 0}, {400, 200, 0}, {200, 300, 0}};
  Object testObject;
  testObject.addTriangle(testTriangle);
  world_.addObject(testObject);

  renderer_.render(world_, screen_);
  screen_.show();
}

}  // namespace renderer
