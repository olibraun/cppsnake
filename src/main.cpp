#include <SFML/Graphics.hpp>
#include <vector>
#include "./classes/GridBlock.hpp"
#include "./debug/setupDebugBoxes.hpp"
#include "./classes/Snake.hpp"
#include "./classes/Food.hpp"

const unsigned int windowWidth = 800;
const unsigned int windowHeight = 800;

int main() {
  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake");

  const float BLOCKSIZE = ((float) windowWidth / 12.0);

  Snake player(BLOCKSIZE);

  std::vector<Food> food_array;

  Food food(BLOCKSIZE);
  food.setGridPosition(8, 7);

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

    // Player update
    player.update();
    player.eatFood(food);

    // Rendering
    window.clear();

    food.render(window);
    player.render(window);

    window.display();
  }

  return 0;
} 