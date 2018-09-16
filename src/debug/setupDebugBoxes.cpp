#ifndef DEBUGBOXES
#define DEBUGBOXES

#include<vector>

#include "../classes/GridBlock.hpp"

void setupDebugBoxes(std::vector<GridBlock>& blocks, float BLOCKSIZE) {
  GridBlock block1(BLOCKSIZE);
  block1.setGridPosition(0, 0);
  block1.setColor(sf::Color::Red);
  blocks.push_back(block1);

  GridBlock block2(BLOCKSIZE);
  block2.setGridPosition(0, 1);
  block2.setColor(sf::Color::Green);
  blocks.push_back(block2);

  GridBlock block3(BLOCKSIZE);
  block3.setGridPosition(0, 2);
  block3.setColor(sf::Color::Yellow);
  blocks.push_back(block3);

  GridBlock block4(BLOCKSIZE);
  block4.setGridPosition(0, 3);
  block4.setColor(sf::Color::Blue);
  blocks.push_back(block4);

  GridBlock block5(BLOCKSIZE);
  block5.setGridPosition(0, 4);
  block5.setColor(sf::Color::Magenta);
  blocks.push_back(block5);

  GridBlock block6(BLOCKSIZE);
  block6.setGridPosition(0, 5);
  block6.setColor(sf::Color::Cyan);
  blocks.push_back(block6);

  GridBlock block7(BLOCKSIZE);
  block7.setGridPosition(0, 6);
  block7.setColor(sf::Color::Red);
  blocks.push_back(block7);

  GridBlock block8(BLOCKSIZE);
  block8.setGridPosition(0, 7);
  block8.setColor(sf::Color::Green);
  blocks.push_back(block8);

  GridBlock block9(BLOCKSIZE);
  block9.setGridPosition(0, 8);
  block9.setColor(sf::Color::Yellow);
  blocks.push_back(block9);

  GridBlock block10(BLOCKSIZE);
  block10.setGridPosition(0, 9);
  block10.setColor(sf::Color::Blue);
  blocks.push_back(block10);

  GridBlock block11(BLOCKSIZE);
  block11.setGridPosition(0, 10);
  block11.setColor(sf::Color::Magenta);
  blocks.push_back(block11);

  GridBlock block12(BLOCKSIZE);
  block12.setGridPosition(0, 11);
  block12.setColor(sf::Color::Cyan);
  blocks.push_back(block12);
}

#endif