#include "application.h"

#include "loader.h"
#include "triangle.h"

namespace renderer {

Application::Application()
    : runtime_(windowWidth_, windowHeight_, windowTitle_),
      camera_(windowWidth_, windowHeight_),
      view_(runtime_.window(), windowWidth_, windowHeight_) {
}

void Application::run() {
  Object model = Loader::load("../models/kettle.obj");
  world_.addObject(std::move(model));
  runtime_.run(world_, renderer_, camera_, view_);
}

}  // namespace renderer
