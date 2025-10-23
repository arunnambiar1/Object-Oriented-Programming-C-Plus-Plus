#include <iostream>
#include "Charmander.h"
using namespace std;

int main(){
    vector<string> pokemonType;
    pokemonType.push_back("Fire");

    vector<string> skills;
    skills.push_back("Growl");
    skills.push_back("Scratch");

    cout << "-------Constructor Created--------\n";
    Charmander charlie = Charmander("Charlie", 100, 4, 4, pokemonType, skills);

    // -------- Direct Speak ----------
    cout << "\n--------Direct Speak---------\n";
    charlie.speak();

    // Pokemon pointer to Charmander (base* -> derived)
    Pokemon* p1 = &charlie;
    cout << "\n-------- Speak called from Pokemon Pointer --------\n";
    p1->speak();   // calls Charmander::speak() because speak() is virtual

    // Charmander pointer to Charmander
    Charmander* c1 = &charlie;
    cout << "\n-------- Speak called from Charmander Pointer --------\n";
    (*c1).speak();

    // Print stats
    cout << "\n-------- Print Stats --------\n";
    charlie.printStats();

    return 0;
}
