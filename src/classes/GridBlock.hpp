#pragma once

#include <SFML/Graphics.hpp>

// This class is a data structure for blocks which are to be rendered on the SFML canvas.
// They behave as if there were a grid on the canvas.
// The blocks' positions are expressed as integers in terms of that grid.

class GridBlock {
  private:
  float myBlockSize;
  int myGridX;
  int myGridY;
  sf::Color myColor;

  float getRealXPosition();
  float getRealYPosition();

  public:
  GridBlock();
  GridBlock(float blocksize);
  virtual void render(sf::RenderWindow &window);
  void setColor(sf::Color color);
  void setGridPosition(int x, int y);
  std::vector<int> getGridPosition();
  void printDebugInfo();
  float getBlockSize();
};