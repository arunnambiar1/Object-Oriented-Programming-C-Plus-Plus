#include "Game.h"
#include <iostream>
#include <random>
#include <iterator>
using std::cout;

Game::Game() {}

Game::~Game() {

  for (RPG* p : players) delete p;
  players.clear();
  live_players.clear();
}

/**
 * @brief creates up to n RPG pointers and updates names NPC_i;
 *        populates live_players with 0..n-1
 */
void Game::generatePlayers(int n) {
  for (int i = 0; i < n; ++i) {
    players.push_back(new RPG());   // default NPC
    std::string new_name = "NPC_" + std::to_string(i);
    players[i]->setName(new_name);
    live_players.insert(i);
  }
}

/**
 * @brief pick a random index from the set live_players
 * @return index for vector 'players'
 */
int Game::selectPlayer() {
  if (live_players.empty()) return -1;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, static_cast<int>(live_players.size()) - 1);

  // advance an iterator to the randomly chosen position
  int randomIndex = dist(gen);
  std::set<int>::iterator it = live_players.begin();
  std::advance(it, randomIndex);
  return *it; // actual player index
}

/**
 * @brief winner gains exp/level, loser removed from live_players, winner's hits reset, print result
 */
void Game::endRound(RPG* winner, RPG* loser, int loserIndex) {
  if (!winner || !loser) return;

  winner->setHitsTaken(0);      // heal the winner
  winner->updateExpLevel();     // +50 exp; maybe level up

  // report
  cout << winner->getName() << " won against " << loser->getName() << "\n";

  // remove loser from set of live players
  live_players.erase(loserIndex);
}

/**
 * @brief choose 2 distinct players; have them attack back and forth until one dies; call endRound
 */
void Game::battleRound() {
  if (live_players.size() < 2) return;

  int i1 = selectPlayer();
  int i2 = selectPlayer();

  // If we picked the same one twice, try again
  if (i1 == i2) { battleRound(); return; }

  RPG* player1 = players[i1];
  RPG* player2 = players[i2];

  // fight
  while (player1->isAlive() && player2->isAlive()) {
    player1->attack(player2);
    if (!player2->isAlive()) break;
    player2->attack(player1);
  }

  // determine winner/loser and finish the round
  if (player1->isAlive())
    endRound(player1, player2, i2);
  else
    endRound(player2, player1, i1);
}

/**
 * @brief run until one player left in 'live_players'
 */
void Game::gameLoop() {
  while (live_players.size() > 1) {
    battleRound();
  }
}

/**
 * @brief Print everyone's final stats
 */
void Game::printFinalResults() {
  for (RPG* p : players) p->printStats();
}
