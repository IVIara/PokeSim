#ifndef COMBAT_H
#define COMBAT_H
#include "Dresseur.h"

class Combat
{
    public:
        Combat(Dresseur a,Dresseur b);
        void affiche();
        void turn();
        void fin();
        void attaque();




    private:
        Dresseur m_att;
        Dresseur m_def;
};

#endif // COMBAT_H
