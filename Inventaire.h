#ifndef INVENTAIRE_H
#define INVENTAIRE_H
#include "Objet.h"
#include <iostream>
#include <vector>

class Inventaire
{
    public:
        Inventaire();
        void add(Objet nv);
        void rm(Objet rm);
        void menu();
        Objet getObj(int x);
        int getSize();


    private:
        std::vector<Objet> m_inv;


};

#endif // INVENTAIRE_H
