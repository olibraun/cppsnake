#include "Food.hpp"
#include <iostream>
#include "../misc/global_constants.hpp"

Food::Food(float blocksize) : 
GridBlock(blocksize) {
  GridBlock::setColor(sf::Color::Blue);
}

void Food::setRandomGridPosition() {
  int a, b;
  a = rand() % global::blocknumber;
  b = rand() % global::blocknumber;
  GridBlock::setGridPosition(a, b);
}