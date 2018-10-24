#include "Capacite.h"
#include <iostream>
#include <string>

using namespace std;


Capacite::Capacite() : m_power(0), m_precision(0), m_ppBase(0), m_nom("vide")
{
    Type type(1);
    m_type = type;
    m_pp = m_ppBase;
}

Capacite::Capacite(int power, int precision, int pp, Type type, string nom) : m_power(power), m_precision(precision), m_ppBase(pp), m_type(type), m_nom(nom)
{
    m_pp = m_ppBase;
}

int Capacite::getPower()
{
    return m_power;
}

string Capacite::getNom()
{
    return m_nom;
}

int Capacite::getPP()
{
    return m_pp;
}

int Capacite::getPPbase()
{
    return m_ppBase;
}

void Capacite::setPP(int a)
{
    m_pp = a;
}

Type Capacite::getType()
{
    return m_type;
}

int Capacite::getID()
{
    return m_id;
}
