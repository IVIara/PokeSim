#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
#include "Capacite.h"
#include "Objet.h"
#include "Combat.h"
#include "Inventaire.h"
#include "Dresseur.h"

using namespace std;

//120x30


int main()
{
    Dresseur Sacha("Sacha");
    Dresseur Rival("Rival");
    Pokemon bulbizarre("Bulbizarre",11,5,10,49,49,65,65,0,1);
    Pokemon salameche("Salameche",9,5,12,52,43,60,50,0,1);

    Sacha.addPokemon(bulbizarre);
    Rival.addPokemon(salameche);

    Capacite flammeche(40,100,25,9,"Flammeche");
    Rival.technique(0,flammeche);



    Combat a(Sacha,Rival);
    a.affiche();


    return 0;
}
