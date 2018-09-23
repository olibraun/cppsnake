#include "Food.hpp"
#include <iostream>

Food::Food(float blocksize) : 
GridBlock(blocksize) {
  GridBlock::setColor(sf::Color::Blue);
}

void Food::setRandomGridPosition() {
  int a, b;
  a = rand() % 12;
  b = rand() % 12;
  GridBlock::setGridPosition(a, b);
}