#include "screen.h"

namespace renderer {

Screen::Screen()
    : window_(sf::RenderWindow(sf::VideoMode({width_, height_}), windowName_)),
      image_(sf::Image({width_, height_}, windowColor_)) {
}

void Screen::setPixel(uint32_t x, uint32_t y, sf::Color color) {
  image_.setPixel({x, y}, color);
}

void Screen::show() {
  while (window_.isOpen()) {
    while (const std::optional event = window_.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window_.close();
      }
    }

    sf::Texture texture;
    if (!texture.loadFromImage(image_)) {
      throw std::runtime_error("Texture::loadFromImage error");
    }
    sf::Sprite sprite(texture);

    window_.draw(sprite);
    window_.display();
  }
}

}  // namespace renderer
