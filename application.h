#pragma once

#include "camera.h"
#include "renderer.h"
#include "runtime.h"
#include "screen.h"
#include "view.h"

namespace renderer {

class Application {
 private:
  RunTime runtime_;
  View view_;
  World world_;
  Renderer renderer_;
  Camera camera_;
  static constexpr int windowWidth_ = 1000;
  static constexpr int windowHeight_ = 800;
  static constexpr const char* windowTitle_ = "3D Renderer";

 public:
  Application();
  void run();
};

}  // namespace renderer
