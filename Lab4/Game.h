#ifndef GAME_H
#define GAME_H

#include <vector>
#include <set>
#include "RPG.h"

class Game {
public:
  Game();
  ~Game();

  void generatePlayers(int n); // creates n RPG objects names NPC_0..NPC_n-1
  int  selectPlayer();         // pick rand index from live_players
  void endRound(RPG* winner, RPG* loser, int loserIndex);
  void battleRound();          // pick 2 players; fight until one dies; call endRound
  void gameLoop();             // keep battling until 1 remains
  void printFinalResults();    

private:
  std::vector<RPG*> players; // pointers to RPG 
  std::set<int>      live_players; // indices of players alive
};

#endif
