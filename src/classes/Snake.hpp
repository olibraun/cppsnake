#pragma once

#include "GridBlock.hpp"
#include "Food.hpp"

class Snake : public GridBlock {
  private:
  int myStepX;
  int myStepY;
  int myTimer;
  const static int myTimerDefault = 500;

  public:
  Snake();
  Snake(float blocksize);
  void update();
  void handleKeyboardInput(sf::Event& event);
  void eatFood(Food& food);
};