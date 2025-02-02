#pragma once

#include "renderer.h"
#include "screen.h"

namespace renderer {

class Application {
 private:
  Renderer renderer_;
  Screen screen_;

 public:
  Application();
  void run();
};

}  // namespace renderer
