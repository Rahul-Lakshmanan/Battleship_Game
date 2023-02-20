//
// Created by Christina Lei on 5/12/21.
//

#include <iostream>
#include "gameOver.h"
#include "Player.h"
#include "Ship.h"

bool Battleship::game_over(Player& player1, Player& player2) {
    bool player1Alive, player2Alive;

    player1Alive = has_floating_ships(player1);
    player2Alive = has_floating_ships(player2);

    if (player1Alive && player2Alive) {
        return false;
    } else {
        if (player1Alive) {
            std::cout << player1.get_name() << " won the game!" << std::endl;
        } else {
            std::cout << player2.get_name() << " won the game!" << std::endl;
        }
        return true;
    }
}

bool Battleship::has_floating_ships(Player& player) {
    for (int i = 0; i < player.get_ships().size(); ++i) {
        bool playerShipAfloat = player.get_ships().at(i).get_float_status();
        if (playerShipAfloat) {
            return true;
        }
    }
    return false;
}