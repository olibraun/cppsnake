#include <SFML/Graphics.hpp>
#include <vector>
#include "./classes/GridBlock.hpp"
#include "./debug/setupDebugBoxes.hpp"
#include "./classes/Snake.hpp"
#include "./classes/Food.hpp"
#include "./misc/global_constants.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(global::windowWidth, global::windowHeight), "Snake");

  Snake player(global::BLOCKSIZE);

  std::vector<Food> food_array;

  Food food(global::BLOCKSIZE);
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