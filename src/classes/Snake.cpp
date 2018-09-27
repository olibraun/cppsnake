#include "Snake.hpp"
#include <iostream>
#include "../misc/global_constants.hpp"

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
  std::vector<int> position_vector = GridBlock::getGridPosition();
  int xpos = position_vector[0];
  int ypos = position_vector[1];

  // "Wrap around" behavior: If the snake passes the right end of the screen, it is set to the left etc.
  std::cout << "Test" << std::endl;
  if (xpos > global::blocknumber && myStepX > 0) {
    xpos = 0;
  } else if (xpos < 0 && myStepX < 0) {
    xpos = global::blocknumber - 1;
  } else if (ypos < 0 && myStepY < 0) {
    ypos = global::blocknumber;
  } else if (ypos > global::blocknumber && myStepY > 0) {
    ypos = -1;
  }

  GridBlock::setGridPosition(xpos, ypos);

  if(myTimer <= 0) {
    GridBlock::setGridPosition(xpos + myStepX, ypos + myStepY);

    // This is the motion of the snake
    if(myTail.size() > 0) {
      // The head has already moved on to its next location
      // Now move the first piece in the tail to the previous position of the head
      // That location is still stored in the variable position_vector
      // Before that, store the current location of the first tailpiece
      std::vector<int> current_pos = myTail[0].getGridPosition();
      std::vector<int> next_pos = myTail[0].getGridPosition();
      myTail[0].setGridPosition(position_vector[0], position_vector[1]);
  
      // Now the second tailpiece needs to move to the position of the first,
      // the third to the place of the second, and so forth
      for(int i = 1; i < myTail.size(); i++) {
        next_pos = myTail[i].getGridPosition();
        myTail[i].setGridPosition(current_pos[0], current_pos[1]);
        current_pos = next_pos;
      }
    }

    myTimer = myTimerDefault;
  }
  myTimer--;
}

void Snake::handleKeyboardInput(sf::Event& event) {
  sf::Keyboard::Key keycode = event.key.code;
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
  std::vector<int> food_position = food.getGridPosition();
  std::vector<int> snake_position = this->getGridPosition();
  if (food_position == snake_position) {
    // Create a new piece for the tail
    GridBlock tailblock(GridBlock::getBlockSize());
    tailblock.setColor(sf::Color::Green);
    tailblock.setGridPosition(food_position[0], food_position[1]);
    myTail.push_back(tailblock);

    // Move the food to a new place
    food.setRandomGridPosition();
  }
}

void Snake::render(sf::RenderWindow &window) {
  // Render the tail
  for(GridBlock& piece_of_tail : myTail) {
    piece_of_tail.render(window);
  }

  // Render the head
  GridBlock::render(window);
}