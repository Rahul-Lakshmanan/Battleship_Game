#include "read.h"
#include "setup.h"
#include "Player.h"
#include "Ship.h"
#include "board.h"

int main(int argc, char *argv[]) {
  int numRow;
  int numCol;
  int numShips;
  std::vector<Battleship::Ship> ships;

  // read file
  ships = Battleship::readFile(argv, numRow, numCol, numShips, ships);

  // create players
  Battleship::Player player1(ships, numRow, numCol);
  Battleship::Player player2(ships, numRow, numCol);

  // setup game
  Battleship::setup_game(player1, player2);
  // play game
  Battleship::play_game(player1, player2);

  // free board
  player1.get_board("placement").delete_boards();
  player1.get_board("firing").delete_boards();
  player2.get_board("placement").delete_boards();
  player2.get_board("firing").delete_boards();
}
