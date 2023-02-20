//
// Created by rahul on 5/9/2021.
//

#ifndef BATTLESHIP__GAME_H_
#define BATTLESHIP__GAME_H_


namespace Battleship {
class Board;
class Player;
class Ship;

void play_game(Player& player1, Player& player2);
void display_boards(Player& player);
std::string attack_player(Player& attacker, Player& victim);
void display_hit_message(const std::string& hitMessage);
}

#endif //BATTLESHIP__GAME_H_
