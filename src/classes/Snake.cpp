#include "Snake.hpp"

Snake::Snake() {
}

Snake::Snake(float blocksize) : GridBlock(blocksize) {
  myStepX = 0;
  myStepY = 0;
  GridBlock::setColor(sf::Color::Green);
  GridBlock::setGridPosition(6, 6);
}

void Snake::update() {
  auto position_vector = GridBlock::getGridPosition();
  int xpos = position_vector[0];
  int ypos = position_vector[1];
  GridBlock::setGridPosition(xpos + myStepX, ypos + myStepY);
}

void Snake::move(int x, int y) {
  if(x != 0 && y != 0) {
    // This is an error, the snake cannot move diagonally
    return;
  } else if (x != 0) {
    myStepX = x > 0 ? 1 : -1;
    return;
  } else if (y != 0) {
    myStepY = y > 0 ? 1 : -1;
    return;
  }
  if(x == 0 && y == 0) {
    myStepX = 0;
    myStepY = 0;
  }
}

void Snake::checkKeyboardInput() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    move(1, 0);
    return;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    move(-1, 0);
    return;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    move(0, -1);
    return;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    move(0, 1);
    return;
  } else {
    move(0, 0);
    return;
  }
}