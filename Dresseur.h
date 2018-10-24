#ifndef DRESSEUR_H
#define DRESSEUR_H
#include <string>
#include <vector>
#include "Inventaire.h"
#include "Pokemon.h"


class Dresseur
{
    public:
        Dresseur();
        Dresseur(std::string);
        std::string getName() { return m_name; }
        void setName(std::string val) { m_name = val; }
        Inventaire getInv() { return m_inv; }
        void setInv(Inventaire val) { m_inv = val; }
        int getNbPkmn() { return m_nbPkmn;}
        void setNbPkmn(int val) { m_nbPkmn = val; }
        Pokemon getPokemon(int index);
        void addPokemon(Pokemon pkmn);
        void releasePkmn(int index);
        void saveDresseur();
        bool objets();
        void useObj(Objet obj);
        void technique(int a,Capacite ct);

    private:
        std::vector<Pokemon> m_equipe;
        std::string m_name;
        int m_nbPkmn;
        Inventaire m_inv;
};

#endif // DRESSEUR_H
