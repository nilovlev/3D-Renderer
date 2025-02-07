#pragma once

#include "renderer.h"
#include "screen.h"

namespace renderer {

class Application {
 private:
  World world_;
  Renderer renderer_;
  Screen screen_;

 public:
  Application() = default;
  void run();
};

}  // namespace renderer
