#include "runtime.h"

namespace renderer {

RunTime::RunTime(int width, int height, const std::string& windowTitle)
    : window_(sf::RenderWindow(sf::VideoMode({static_cast<unsigned>(width), static_cast<unsigned>(height)}), windowTitle)) {
}

bool RunTime::handleEvents() {
  while (const std::optional event = window_.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      window_.close();
      return false;
    }
  }
  return true;
}

void RunTime::handleInput(Camera& camera) {
  float speed = 0.5f;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) camera.moveForward(speed);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) camera.moveBackward(speed);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) camera.moveLeft(speed);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)) camera.moveRight(speed);
  
  float angle = 0.05f;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) camera.rotateLeft(angle);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) camera.rotateRight(angle);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)) camera.rotateUp(angle);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)) camera.rotateDown(angle);
}

void RunTime::run(const World& world, const Renderer& renderer, Camera& camera, View& view) {
  Screen screen(window_.getSize().x, window_.getSize().y);
  while (window_.isOpen()) {
    if (!handleEvents()) return;
    handleInput(camera);

    screen.clear();
    screen = renderer.render(world, std::move(screen), camera);
    view.show(screen);
  }
}

sf::RenderWindow* RunTime::window() {
  return &window_;
}

}  // namespace renderer
