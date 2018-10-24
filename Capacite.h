#ifndef CAPACITE_H_INCLUDED
#define CAPACITE_H_INCLUDED
#include <string>
#include "Type.h"

class Capacite
{
public :
Capacite();
Capacite(int power, int precision, int pp, Type type,std::string nom);
int getPower();
std::string getNom();
int getPP();
int getPPbase();
void setPP(int a);
Type getType();
int getID();

private :
    int m_power;
    int m_precision;
    int m_ppBase;
    int m_pp;
    std::string m_categorie;
    Type m_type;
    int m_id;
    std::string m_nom;
};

#endif // CAPACITE_H_INCLUDED
