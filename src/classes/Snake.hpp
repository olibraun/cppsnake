#pragma once

#include "GridBlock.hpp"
#include "Food.hpp"
#include <vector>

class Snake : public GridBlock {
  private:
  int myStepX;
  int myStepY;
  int myTimer;
  const static int myTimerDefault = 500;
  std::vector<GridBlock> myTail;

  public:
  Snake();
  Snake(float blocksize);
  void update();
  void handleKeyboardInput(sf::Event& event);
  void eatFood(Food& food);
  void render(sf::RenderWindow &window) override;
};