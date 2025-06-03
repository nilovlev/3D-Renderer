#pragma once

#include <SFML/Graphics.hpp>

#include "screen.h"

namespace renderer {

class View {
 private:
  sf::RenderWindow* window_;
  sf::Texture texture_;

 public:
  View(sf::RenderWindow* window, uint32_t width, uint32_t height);
  void show(const Screen& screen);
};

}  // namespace renderer
