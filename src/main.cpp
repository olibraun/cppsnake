#include <SFML/Graphics.hpp>
#include<vector>

#include "./classes/GridBlock.hpp"
#include "./debug/setupDebugBoxes.hpp"
#include "./classes/Snake.hpp"

unsigned int windowWidth = 800;
unsigned int windowHeight = 800;

int main() {
  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake");

  float BLOCKSIZE = ((float) windowWidth / 12.0);

  // std::vector<GridBlock> blocks;

  // setupDebugBoxes(blocks, BLOCKSIZE);

  Snake player(BLOCKSIZE);

  while (window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      switch(event.type) {
        case sf::Event::Closed:
          window.close();
          break;
        
        case sf::Event::KeyPressed:
          player.handleKeyboardInput(event);
          break;

        default:
          break;
      }
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    player.update();
    player.render(window);
    window.display();
  }

  return 0;
} 