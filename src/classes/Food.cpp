#include "Food.hpp"

Food::Food(float blocksize) : 
GridBlock(blocksize) {
  GridBlock::setColor(sf::Color::Blue);
}