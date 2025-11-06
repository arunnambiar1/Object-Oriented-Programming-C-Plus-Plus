#include "RPG.h"
#include <iostream>
#include <random>
using std::cout;

RPG::RPG() : name("NPC"), hits_taken(0), luck(0.10f), exp(50.0f), level(1) {}
RPG::RPG(string name, int hits_taken, float luck, float exp, int level)
: name(name), hits_taken(hits_taken), luck(luck), exp(exp), level(level) {}

bool   RPG::isAlive()      const { return hits_taken < MAX_HITS_TAKEN; }
string RPG::getName()      const { return name; }
int    RPG::getHitsTaken() const { return hits_taken; }
float  RPG::getLuck()      const { return luck; }
float  RPG::getExp()       const { return exp; }
int    RPG::getLevel()     const { return level; }

void RPG::setName(string n) { name = n; }

void RPG::setHitsTaken(int new_hits) {
  hits_taken = new_hits;
  if (hits_taken < 0) hits_taken = 0;
}

void RPG::updateExpLevel() {
  // Increase exp by 50; if we cross 100, level up and adjust stats 
  exp += 50.0f;
  if (exp >= 100.0f) {
    level += 1;
    exp = 0.0f;
    luck += 0.10f;           
    if (luck > 1.0f) luck = 1.0f;
  }
}

/**
 * @brief try to hit opponent; higher opponent luck → more misses.
 * hit if random in [0,1) > HIT_FACTOR * opponent->luck
 * if hit: opponent's hits_taken++
 */
void RPG::attack(RPG* opponent) {
  if (!opponent) return;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dis(0.0, 1.0);

  float random_num = static_cast<float>(dis(gen));

  bool hit = random_num > (HIT_FACTOR * opponent->getLuck());
  if (hit) {
    opponent->setHitsTaken(opponent->getHitsTaken() + 1);
  }
  // exp/leveling happens at endRound (winner)
}

void RPG::printStats() const {
// "Name: NPC_X  Hits Taken: X  Luck: 0.xxxxxx  Exp: X.xxxxxx  Level: X  Status: Alive/Dead"
  printf("Name: %s\t Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\t Status: %s\n",
         name.c_str(), hits_taken, luck, exp, level, (isAlive() ? "Alive" : "Dead"));
}

RPG::~RPG() { /* empty per instructions */ }
