#pragma once

#include <SFML/Graphics.hpp>

#include "camera.h"
#include "renderer.h"
#include "view.h"
#include "world.h"

namespace renderer {

class RunTime {
 private:
  sf::RenderWindow window_;

 public:
  RunTime(int width, int height, const std::string& windowTitle);
  bool handleEvents();
  void handleInput(Camera& camera);
  void run(const World& world, const Renderer& renderer, Camera& camera, View& view);
  sf::RenderWindow* window();
};

}  // namespace renderer
