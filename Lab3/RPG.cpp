//RPG.cpp
#include "RPG.h"

RPG ::RPG() : name("Anon"), hits_taken(0), luck(0.5), exp(0), level(1) {}

RPG ::RPG(string name, int hits_taken, float luck, float exp, int level)
    : name(name), hits_taken(hits_taken), luck(luck), exp(exp), level(level) {}

bool RPG ::isAlive() const {
    return hits_taken < MAX_HITS_TAKEN;
}

void RPG :: setHitsTaken(int new_hits) {
    hits_taken = new_hits;
}


string RPG :: getName() const { return name; }
int RPG :: getHitsTaken() const { return hits_taken; }
float RPG :: getLuck() const { return luck; }
float RPG :: getExp() const { return exp; }
int RPG :: getLevel() const { return level; }
