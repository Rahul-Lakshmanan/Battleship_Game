//
// Created by Christina Lei on 5/12/21.
//

#ifndef BATTLESHIP_GAMEOVER_H
#define BATTLESHIP_GAMEOVER_H

namespace Battleship {
    class Player;
    bool game_over(Player& player1, Player& player2);
    bool has_floating_ships(Player& player);
}

#endif //BATTLESHIP_GAMEOVER_H
