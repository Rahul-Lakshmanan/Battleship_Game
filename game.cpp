//
// Created by rahul on 5/9/2021.
//

#include <iostream>
#include <string>
#include "game.h"
#include "Player.h"
#include "Ship.h"
#include "inputValidation.h"
#include "gameOver.h"

void Battleship::play_game(Player& player1, Player& player2) {
    std::string hitMessage;

    do {
        display_boards(player1);
        hitMessage = attack_player(player1, player2);
        display_boards(player1);
        display_hit_message(hitMessage);

        display_boards(player2);
        hitMessage = attack_player(player2, player1);
        display_boards(player2);
        display_hit_message(hitMessage);
    } while (not game_over(player1, player2));
}

// THIS FUNCTION WILL PROBABLY NEED FORMAT ADJUSTING
void Battleship::display_boards(Player& player) {
  // prints firing board
  std::cout << player.get_name() << "'s Firing Board" << std::endl;
  player.get_board("firing").print_board();
  std::cout << "\n\n";
  // prints placement board
  std::cout << player.get_name() << "'s Placement Board" << std::endl;
  player.get_board("placement").print_board();
}

std::string Battleship::attack_player(Player& attacker, Player& victim) {
  int attackRow, attackColumn;
  std::string message;

  do {
    std::cout << attacker.get_name() << ", where would you like to fire?" << std::endl;
    std::cout << "Enter your attack coordinate in the form row col: " << std::endl;
    std::cin >> attackRow >> attackColumn;
  } while (not valid_attack_coordinate(attackRow, attackColumn, victim.get_board("placement")));

  message = attacker.attack(attackRow, attackColumn, victim);
  return message;
}

void Battleship::display_hit_message(const std::string& hitMessage) {
    std::cout << hitMessage << "\n";

}
