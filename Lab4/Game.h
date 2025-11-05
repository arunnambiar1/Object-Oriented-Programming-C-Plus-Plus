#ifndef GAME_H
#define GAME_H

#include <vector>
#include <set>
#include "RPG.h"

class Game {
public:
  Game();
  ~Game();

  void generatePlayers(int n); // creates n RPG objects (on heap), names NPC_0..NPC_n-1
  int  selectPlayer();         // pick a random *index* from live_players (set<int>)
  void endRound(RPG* winner, RPG* loser, int loserIndex);
  void battleRound();          // pick 2 players; fight until one dies; call endRound
  void gameLoop();             // keep battling until only 1 remains
  void printFinalResults();    // printStats on all

private:
  std::vector<RPG*> players; // pointers to RPG (so we can store polymorphic types later, too)
  std::set<int>      live_players; // indices of players in 'players' who are alive
};

#endif
