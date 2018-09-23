#include <SFML/Graphics.hpp>
#include <vector>

#include "./classes/GridBlock.hpp"
#include "./debug/setupDebugBoxes.hpp"
#include "./classes/Snake.hpp"
#include "./classes/Food.hpp"

unsigned int windowWidth = 800;
unsigned int windowHeight = 800;

int main() {
  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake");

  float BLOCKSIZE = ((float) windowWidth / 12.0);

  Snake player(BLOCKSIZE);

  std::vector<Food> food_array;

  // Distribute food on the grid (make this one random piece of food later)
  Food* food1 = new Food(BLOCKSIZE);
  food1->setGridPosition(2, 5);
  food_array.push_back(*food1);
  delete food1;

  Food food2(BLOCKSIZE);
  food2.setGridPosition(8, 7);
  food_array.push_back(food2);

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
    for(Food& food : food_array) {
      food.render(window);
      player.eatFood(food);
    }
    player.render(window);
    window.display();
  }

  return 0;
} 