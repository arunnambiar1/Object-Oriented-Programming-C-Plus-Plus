//main.cpp
#include <iostream>
#include "RPG.h"
using namespace std;

int main() {
    RPG p1 = RPG("Wiz", 0, 0.2, 60, 1);
    RPG p2 = RPG();

    printf("&s Current Stts\n", p1.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n", p1.getHitsTaken(), p1.getLuck(), p1.getExp(), p1.getLevel());

    //PRINT the same for p2
    printf("&s Current Stts\n", p2.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n", p2.getHitsTaken(), p2.getLuck(), p2.getExp(), p2.getLevel());   

    //CALL setHitsTaken(new_hit) on either p1 and p2
    int new_hit = 3;
    p2.setHitsTaken(new_hit);

    cout << "\nP2 hits taken"
    // PRINT out the hits_taken
    << new_hit << "\n";



    cout << "0 is dead, 1 is alive\n";
    // CALL isAlive() on both p1 and p2
    cout << "P1 " << (p1.isAlive() ? 1 : 0) << "\n";
    cout << "P2 " << (p2.isAlive() ? 1 : 0) << "\n";

    return 0;
}