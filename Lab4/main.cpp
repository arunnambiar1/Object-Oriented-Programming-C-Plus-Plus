#include <iostream>
#include "RPG.h"
#include "Game.h"
using namespace std;

int main() {
  // Create a Game
  Game g;

  // number of players
  int num_players = 10;

  // create NPC_0..NPC_9 and mark them alive
  g.generatePlayers(num_players);

  // run the tournament
  g.gameLoop();

  // print final table
  g.printFinalResults();

  return 0;
}
