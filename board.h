//
// Created by Christina Lei on 5/5/21.
//

#ifndef BATTLESHIP_GAME_H
#define BATTLESHIP_GAME_H

#include <string>
#include "game.h"

namespace Battleship {
    class Board {
    public:
        Board(const int& numRows, const int& numCols);
        void print_board() const;
        char get_piece(const int& row, const int& column) const;
        void set_piece(const int& row, const int& column, const char& piece);
        void set_ship(const int& row, const int& column, const int& shipSize,
                      const char& orientation, const char& shipType);
        int get_bound(const std::string& dimension) const;
        void delete_boards();
    private:
        int rows;
        int cols;
        char** board;
    };
}

#endif //BATTLESHIP_GAME_H
