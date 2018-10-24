#include "Dresseur.h"
#include "Pokemon.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;



Objet potion(1);

Dresseur::Dresseur()
{
    m_name = "dresseur";
    m_nbPkmn = 0;
}

Dresseur::Dresseur(string name) : m_name(name)
{
    m_nbPkmn = 0;
    m_inv.add(potion);
}

Pokemon Dresseur::getPokemon(int index)
{
    return m_equipe[index];
}

void Dresseur::releasePkmn(int index)
{
    m_equipe[index]=m_equipe[m_equipe.size()-1];
    m_equipe.pop_back();
}

void Dresseur::saveDresseur()
{
    ofstream save;
    save.open ("save.txt", ios::in | ios::out | ios::app);
    save << "test"<< endl;
    save << m_name << '\t'; //<< m_type.Getm_nbtype() << '\t' << m_niveau << '\t' << m_pv << '\t' <<  m_MaxPV << '\t' << m_attaque << '\t' << m_defense << '\t' << m_attspe << '\t' << m_defspe;
//    for(int i=0; i<4; i++)
//    {
//        save << '\t' << m_ct[i].getID();
//    }
    for(int i=0; i<4; i++)
    {
        save << '\t' << m_inv.getObj(i).getID();
    }
    save.close();
}

bool Dresseur::objets()
{
    m_inv.menu();
    int choix;
    cin >> choix;
    if(choix<=m_inv.getSize())
    {
        useObj(m_inv.getObj(choix-1));
        return true;
    }
    else
    {
        return false;
    }
}

void Dresseur::useObj(Objet obj)
{
//    cout << m_name << " utilise " << obj.getNom() << " et recupere ";
//
//    if(m_MaxPV-m_pv>obj.getHeal())
//    {
//        cout << obj.getHeal() << "pv !" << endl;
//    }
//    else
//    {
//        cout << m_MaxPV-m_pv << "pv !" << endl;
//    }
//    heal(obj.getHeal());
//    m_inv.rm(obj);

}


void Dresseur::addPokemon(Pokemon pkmn)
{
    m_equipe.push_back(pkmn);
}

void Dresseur::technique(int a, Capacite ct)
{
    m_equipe[a].addCT(ct);
}
