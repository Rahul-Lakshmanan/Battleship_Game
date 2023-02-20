//
// Created by rahul on 5/8/2021.
//

#include "inputValidation.h"
#include <iostream>
#include <algorithm>

bool Battleship::valid_orientation(const char& userInput) {
  if (userInput == 'h' || userInput == 'v' || userInput == 'H' || userInput == 'V') {
    return true;
  } else {
    return false;
  }
}

// check if user input is valid
bool Battleship::valid_placement_coordinates(const int& row, const int& column, const int& shipSize,
                                             const char& orientation, Player& player) {
  // within number of rows
  bool validRow = row >= 0 && row < player.get_board("placement").get_bound("row");
  // within number of columns
  bool validColumn = column >= 0 && column < player.get_board("placement").get_bound("column");
  bool frontOfShipWithinBounds = validRow && validColumn;   // front of ship is somewhere on the board

  if (not frontOfShipWithinBounds) {
    return false;
  }

  bool backOfShipWithinBounds;
  bool shipInterference;

  // check horizontal placement
  if (orientation == 'h') {
    // checks if back of ship is somewhere on board
    backOfShipWithinBounds = column + shipSize <= player.get_board("placement").get_bound("column");
    if (backOfShipWithinBounds) {
      for (int i = column; i < column + shipSize; ++i) {
        if (player.get_board("placement").get_piece(row, i) != '*') {
          shipInterference = true;
          break;
        } else {
          shipInterference = false;
        }
      }
    }
  } else if (orientation == 'v'){ // check vertical placement
    backOfShipWithinBounds = row + shipSize <= player.get_board("placement").get_bound("row");
    if (backOfShipWithinBounds) {
      for (int i = row; i < row + shipSize; ++i) {
        if (player.get_board("placement").get_piece(i, column) != '*') {
          shipInterference = true;
          break;
        } else {
          shipInterference = false;
        }
      }
    }
  } else {
    std::cout << "Error: invalid orientation: inputValidation.cpp valid_placement_coordinates()" << std::endl;
    exit(0);
  }

  if (backOfShipWithinBounds && not shipInterference) {
    return true;
  } else {
    return false;
  }
}

bool Battleship::valid_attack_coordinate(const int& row, const int& column, const Board& placementBoard) {
  if (within_bounds(row, column, placementBoard) && placementBoard.get_piece(row, column) != 'X' &&
      placementBoard.get_piece(row, column) != 'O') {
    return true;
  } else {
    return false;
  }
}

bool Battleship::within_bounds(const int& row, const int& column, const Board& board) {
  bool rowWithinBounds, columnWithinBounds;

  if (row >= 0 && row < board.get_bound("row")) {
    rowWithinBounds = true;
  } else {
    rowWithinBounds = false;
  }
  if (column >= 0 && column < board.get_bound("column")) {
    columnWithinBounds = true;
  } else {
    columnWithinBounds = false;
  }

  return rowWithinBounds && columnWithinBounds;
}

// strip special characters
void Battleship::stripInPlace(std::string& string, const std::string& charsToRemove) {
  lstripInPlace(string, charsToRemove);
  rstripInPlace(string, charsToRemove);
}

// strip special characters from left of word
void Battleship::lstripInPlace(std::string& string, const std::string& charsToRemove) {
  auto itr = string.begin();
  for(; itr != string.end(); ++itr){
    if (!contains(charsToRemove, *itr)) {
      break;
    }
  }
  string.erase(string.begin(), itr);
}

// strip special characters from right of word
void Battleship::rstripInPlace(std::string& string, const std::string& charsToRemove) {
  auto itr = string.rbegin();
  for (; itr != string.rend(); ++itr) {
    if (!contains(charsToRemove, *itr)) {
      break;
    }
  }
  string.erase(itr.base(), string.end());
}

bool Battleship::contains(const std::string& string, char letter) {
  return std::find(string.cbegin(), string.cend(), letter) != string.cend();
}
