#include "GridBlock.hpp"

GridBlock::GridBlock() {

}

GridBlock::GridBlock(float blocksize) {
  myBlockSize = blocksize;
}

void GridBlock::render(sf::RenderWindow &window) {
  sf::RectangleShape shape;

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