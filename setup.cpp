//
// Created by Christina Lei on 5/5/21.
//

#include <iostream>
#include <string>
#include "setup.h"
#include "Player.h"
#include "inputValidation.h"
#include "Ship.h"


void Battleship::setup_game(Player& player1, Player& player2) {
  // set up player 1
  get_name(player1, 1); // gets player's name
  for (int i = 0; i < player1.get_ships().size(); ++i) {    // player places all their ships on board
    player1.get_board("placement").print_board();
    place_ship(player1, player1.get_ships().at(i).get_size(), i);
  }
  player1.get_board("placement").print_board();

  // set up player 2
  get_name(player2, 2);   // gets player name
  for (int i = 0; i < player2.get_ships().size(); ++i) {    // player places all their ships on board
    player2.get_board("placement").print_board();
    place_ship(player2, player2.get_ships().at(i).get_size(), i);
  }
  player2.get_board("placement").print_board();
}

// get player name
void Battleship::get_name(Player& player, const int& playerNumber) {
  std::string playerName;

  do {
    std::cout << "Player " << playerNumber << " please enter your name: " << std::endl;
    getline(std::cin, playerName);
    stripInPlace(playerName);
  } while (playerName == "");

  player.set_name(playerName);
}

// ask user if they want to place ship horizontally or vertically
char Battleship::get_orientation(const std::string& playerName, const char& shipType) {
  std::string userInput;
  char orientation;

  do {
    std::cout << playerName << ", do you want to place " << shipType << " horizontally or vertically?" << std::endl;
    std::cout << "Enter h for horizontal or v for vertical" << std::endl;
    std::cout << "Your choice: " << std::endl;

    getline(std::cin, userInput);
    stripInPlace(userInput);

    if (userInput.length() == 1) {
      orientation = userInput.at(0); // converts orientation from string to character
    } else {
      orientation = 'e';
    }

  } while (!valid_orientation(orientation));

  return orientation;
}

void Battleship::place_ship(Player& player, const int& shipSize, const int& i) {
  char orientation;
  int row, column;
  bool validPlacementCoordinates;

  // get coordinates from user
  do {
    orientation = Battleship::get_orientation(player.get_name(), player.get_ships().at(i).get_type());
    validPlacementCoordinates = Battleship::get_placement_coordinates( row,column, player,
                                                                       player.get_ships().at(i).get_type(),
                                                                       shipSize, orientation);
  } while (not validPlacementCoordinates);

  // place ships on board
  player.get_board("placement").set_ship(row, column, shipSize, orientation,
                                         player.get_ships().at(i).get_type());
  player.get_ships().at(i).set_ship_coordinates(row, column);
}

// ask user where they want to place ship
bool Battleship::get_placement_coordinates(int& rowCoordinate, int& columnCoordinate, Player& player,
                                           const char& shipType, const int& shipSize, const char& orientation) {
  int rowInput, columnInput;

  std::cout << player.get_name() << ", enter the row and column you want to place " << shipType << ", which is "
            << shipSize << " long, at with a space in between row and col: " << std::endl;
  if (std::cin >> rowInput >> columnInput) {
    // check if valid move
    if (valid_placement_coordinates(rowInput, columnInput, shipSize, orientation, player)) {
      rowCoordinate = rowInput;
      columnCoordinate = columnInput;
      fflush(stdin);
      return true;
    } else {
      fflush(stdin);
      return false;
    }
  } else {
    fflush(stdin);
    return false;
  }
}
