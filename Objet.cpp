#include "Objet.h"
#include <iostream>
#include <string>

using namespace std;

Objet::Objet() : m_nom("jouet"), m_id(0),m_heal(0), m_att(0), m_def(0)
{
}

Objet::Objet(int id) : m_id(id)
{
    switch(id)
    {
    case 0 :
        m_nom = "vide";
        m_heal = 0;
        m_att = 0;
        m_def = 0;
        break;
    case 1 :
        m_nom = "Potion";
        m_heal = 20;
        m_att = 0;
        m_def = 0;
        break;
    }
}




string Objet::getNom()
{
    return m_nom;
}

int Objet::getHeal()
{
    return m_heal;
}

bool Objet::getAtt()
{
    return m_att;
}

bool Objet::getDef()
{
    return m_def;
}

int Objet::getID()
{
    return m_id;
}
