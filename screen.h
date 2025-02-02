#pragma once

#include <SFML/Graphics.hpp>

namespace renderer {

class Screen {
 private:
  const uint32_t width_ = 600;
  const uint32_t height_ = 400;
  const std::string windowName_ = "3D-Renderer";
  const sf::Color windowColor_ = sf::Color::Black;
  sf::RenderWindow window_;
  sf::Image image_;

 public:
  Screen();
  void setPixel(uint32_t x, uint32_t y, sf::Color color);
  void show();
};

}  // namespace renderer
