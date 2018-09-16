#pragma once

#include "GridBlock.hpp"

class Snake : public GridBlock {
  private:
  int myStepX;
  int myStepY;

  public:
  Snake();
  Snake(float blocksize);
  void update();
  void move(int x, int y);
  void checkKeyboardInput();
};