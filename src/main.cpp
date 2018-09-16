#include <SFML/Graphics.hpp>
#include<vector>

#include "./classes/GridBlock.hpp"
#include "./debug/setupDebugBoxes.hpp"

unsigned int windowWidth = 800;
unsigned int windowHeight = 800;

int main() {
  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake");

  float BLOCKSIZE = ((float) windowWidth / 12.0);

  std::vector<GridBlock> blocks;

  setupDebugBoxes(blocks, BLOCKSIZE);

  while (window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    for(GridBlock block : blocks) {
      block.render(window);
    }
    window.display();
  }

  return 0;
} 