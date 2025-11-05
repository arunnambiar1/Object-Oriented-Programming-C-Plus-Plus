#ifndef RPG_H
#define RPG_H

#include <string>
#include <cstdio>   // printf
using std::string;

// Constants used by the lab (same spirit as Part 1/2)
const int   MAX_HITS_TAKEN = 3;
const float HIT_FACTOR     = 0.05f;  // bigger means harder to land a hit

class RPG {
public:
  // ---- constructors ----
  RPG();  // default NPC
  RPG(string name, int hits_taken, float luck, float exp, int level);

  // ---- queries (const) ----
  bool   isAlive() const;           // hits_taken < MAX_HITS_TAKEN
  string getName() const;
  int    getHitsTaken() const;
  float  getLuck() const;
  float  getExp() const;
  int    getLevel() const;

  // ---- mutators/actions ----
  void setName(string name);        // REQUIRED (new)
  void setHitsTaken(int new_hits);  // existing from part 1
  void updateExpLevel();            // REQUIRED (new)
  void attack(RPG* opponent);       // REQUIRED (new) – uses RNG + opponent’s luck
  void printStats() const;          // REQUIRED (new)

  ~RPG(); // empty body per assignment

private:
  string name;
  int    hits_taken;
  float  luck;     // 0..1 (higher → harder to hit)
  float  exp;      // 0..∞ ; levels at 100
  int    level;
};

#endif
