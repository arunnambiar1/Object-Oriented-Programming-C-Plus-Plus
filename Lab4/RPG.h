#ifndef RPG_H
#define RPG_H

#include <string>
#include <cstdio>  
using std::string;


const int   MAX_HITS_TAKEN = 3;
const float HIT_FACTOR     = 0.05f;  

class RPG {
public:
  //constructors
  RPG();  
  RPG(string name, int hits_taken, float luck, float exp, int level);

  //accessors
  bool   isAlive() const;           
  string getName() const;
  int    getHitsTaken() const;
  float  getLuck() const;
  float  getExp() const;
  int    getLevel() const;

  //mutators
  void setName(string name);        
  void setHitsTaken(int new_hits);  
  void updateExpLevel();            
  void attack(RPG* opponent);       
  void printStats() const;          

  ~RPG(); 

private:
  string name;
  int    hits_taken;
  float  luck;    
  float  exp;     
  int    level;
};

#endif
