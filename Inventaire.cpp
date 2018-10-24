#include "Inventaire.h"
#include "Objet.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Inventaire::Inventaire()
{
}

void Inventaire::add(Objet nv)
{
    if(m_inv.size()<3)
    {
        m_inv.push_back(nv);
    }
    else
    {
        cout << "Inventaire plein!";
    }
}
void Inventaire::rm(Objet rm)
{
    for(int i=0;i<m_inv.size();i++)
    {
        if(m_inv[i].getID()==rm.getID())
        {
            m_inv[i]=m_inv[m_inv.size()-1];
            m_inv.pop_back();
        }
    }
}

void Inventaire::menu()
{

    cout << endl;
    switch(m_inv.size())
    {
    case 0 :
        cout << "[vide] [vide] [vide]";
        break;
    case 1 :
        cout << "[" << m_inv[0].getNom() << "] [vide] [vide]";
        break;
    case 2 :
        cout << "[" << m_inv[0].getNom() << "] [" << m_inv[1].getNom() << "] [vide]";
        break;
    case 3 :

        break;
    }
    cout << endl;

}

Objet Inventaire::getObj(int x)
{
    return m_inv[x];
}
int Inventaire::getSize()
{
    return m_inv.size();
}
