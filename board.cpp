//
// Created by Christina Lei on 5/5/21.
//

#include "board.h"
#include <cstdlib>
#include <iostream>

Battleship::Board::Board(const int& numRows, const int& numCols) : rows(numRows), cols(numCols){
  // create board
  board = (char**)calloc(rows, sizeof(*board));

  for (int i = 0; i < rows; ++i) {
    board[i] = (char*)calloc(rows, sizeof(*board)); // shouldn't this be cols?
    for (int j = 0; j < cols; ++j) {
      board[i][j] = '*';
    }
  }
}

// print board
void Battleship::Board::print_board() const{
  // print column headers
  std::cout << " ";
  for (int i = 0; i < cols; ++i) {
    std::cout << " " << i;
  }
  std::cout << std::endl;
  //print row headers
  for (int i = 0; i < rows; ++i) {
    std::cout << i;
    // print board pieces
    for (int j = 0; j < cols; ++j) {
      std::cout << " " << this->board[i][j];
    }
    std::cout << std::endl;
  }
}

// get board piece
char Battleship::Board::get_piece(const int& row, const int& column) const{
  return this->board[row][column];
}

// set board piece
void Battleship::Board::set_piece(const int& row, const int& column, const char& piece) {
  this->board[row][column] = piece;
}

// set player ship piece onto board
void Battleship::Board::set_ship(const int& row, const int& column, const int& shipSize, const char& orientation,
                                  const char& shipType) {
  if (orientation ==  'h') {
    for (int i = 0; i < shipSize; ++i) {  // for as long as the length of the ship
      this->board[row][column + i] = shipType;
    }
  } else if (orientation == 'v'){
    for (int i = 0; i < shipSize; ++i) {
      this->board[row + i][column] = shipType;
    }
  } else {
    std::cout << "Error: invalid orientation: board.cpp set_ship()" << std::endl;
  }
}

// get board bounds
int Battleship::Board::get_bound(const std::string& dimension) const{
  if (dimension == "row") {
    return this->rows;    // returns number of rows in board
  } else if (dimension == "column"){
    return this-> cols;   // returns number of columns in board
  } else {
    std::cout << "Error: invalid dimension: board.cpp get_bound()" << std::endl;
    exit(0);
  }
}

// free board
void Battleship::Board::delete_boards() {
    for (int i = 0; i < this->rows; ++i) {
        free(this->board[i]);
    }
    free(this->board);
}
