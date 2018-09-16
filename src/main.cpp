#include <SFML/Graphics.hpp>

unsigned int windowWidth = 1200;
unsigned int windowHeight = 800;

int main() {
  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake");

  while (window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.display();
  }

  return 0;
}