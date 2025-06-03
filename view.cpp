#include "view.h"

namespace renderer {

View::View(sf::RenderWindow* window, uint32_t width, uint32_t height)
	: texture_(sf::Vector2u(width, height)), 
		window_(window) {
}

void View::show(const Screen& screen) {
  texture_.update(screen.pixels().data());
  sf::Sprite sprite(texture_);

  window_->clear();
  window_->draw(sprite);
  window_->display();
}

}  // namespace renderer
