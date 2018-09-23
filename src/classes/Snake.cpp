#include "Snake.hpp"
#include<iostream>

Snake::Snake() {
}

Snake::Snake(float blocksize) : GridBlock(blocksize),
myStepX(0),
myStepY(0),
myTimer(myTimerDefault),
myTail()
{
  GridBlock::setColor(sf::Color::Red);
  GridBlock::setGridPosition(6, 6);
}

void Snake::update() {
  auto position_vector = GridBlock::getGridPosition();
  int xpos = position_vector[0];
  int ypos = position_vector[1];
  if(myTimer <= 0) {
    GridBlock::setGridPosition(xpos + myStepX, ypos + myStepY);
    myTimer = myTimerDefault;
  }
  myTimer--;
  std::cout << myStepX << " " << myStepY << std::endl;
}

void Snake::handleKeyboardInput(sf::Event& event) {
  auto keycode = event.key.code;
  switch(keycode) {
    case sf::Keyboard::Right:
      myStepX = 1;
      myStepY = 0;
      break;

    case sf::Keyboard::Left:
      myStepX = -1;
      myStepY = 0;
      break;

    case sf::Keyboard::Up:
      myStepX = 0;
      myStepY = -1;
      break;

    case sf::Keyboard::Down:
      myStepX = 0;
      myStepY = 1;
      break;

    default:
      break;
  }
}

void Snake::eatFood(Food& food) {
  auto food_position = food.getGridPosition();
  auto snake_position = this->getGridPosition();
  if (food_position == snake_position) {
    std::cout << "Nom nom" << std::endl;
  }
}