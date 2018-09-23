#include "GridBlock.hpp"
#include <iostream>

GridBlock::GridBlock() {
}

GridBlock::GridBlock(float blocksize) {
  myBlockSize = blocksize;
}

void GridBlock::render(sf::RenderWindow &window) {
  sf::RectangleShape shape;

  const sf::Vector2f sizevector{myBlockSize, myBlockSize};
  shape.setSize(sizevector);
  shape.setFillColor(myColor);
  const float x = getRealXPosition();
  const float y = getRealYPosition();
  shape.setPosition(x, y);

  window.draw(shape);
}

void GridBlock::setColor(sf::Color color) {
  myColor = color;
}

float GridBlock::getRealXPosition(){
  return myGridX * myBlockSize;
}

float GridBlock::getRealYPosition(){
  return myGridY * myBlockSize;
}

void GridBlock::setGridPosition(int x, int y) {
  myGridX = x;
  myGridY = y;
}

std::vector<int> GridBlock::getGridPosition() {
  std::vector<int> res;
  res.push_back(myGridX);
  res.push_back(myGridY);
  return res;
}

void GridBlock::printDebugInfo() {
  std::cout << "Block" << std::endl;
  std::cout << "Grid position (x,y): " << myGridX << " , " << myGridY << std::endl;
  std::cout << "Real position (x,y): " << getRealXPosition() << " , " << getRealYPosition() << std::endl;
}

float GridBlock::getBlockSize() {
  return myBlockSize;
}