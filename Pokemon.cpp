#include "Pokemon.h"
#include "Type.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

Capacite vide;
Capacite charge(40,100,35,0,"Charge");




Pokemon::Pokemon() : m_name("unknown"),m_type(1), m_numero(0), m_niveau(5), m_MaxPV(80), m_attaque(90), m_defense(83), m_attspe(83), m_defspe(78), m_precison(100), m_evasion(100), m_attNiv(0), m_defNiv(0)
{
    m_pv = m_MaxPV;
}

Pokemon::Pokemon(string name, Type type,int niveau,float pv,int att,int def, int attspe, int defspe, int stade, bool canEvolve) : m_name(name),m_type(type),m_niveau(niveau),m_MaxPV(pv), m_attaque(att), m_defense(def),
    m_attspe(attspe), m_defspe(defspe), m_precison(100), m_evasion(100), m_stade(stade), m_canEvolve(canEvolve)
{

    m_pv = m_MaxPV;
    m_ct.push_back(charge);
    m_nbCT = 1;
    m_niveau = 5;
    m_exp = 53;
    m_expOnKill = 65;
}

void Pokemon::savePokemon()
{
    ofstream save;
    save.open ("save.txt", ios::in | ios::out | ios::app);
    save << "test"<< endl;
    save << m_name << '\t' << m_type.Getm_nbtype() << '\t' << m_niveau << '\t' << m_pv << '\t' <<  m_MaxPV << '\t' << m_attaque << '\t' << m_defense << '\t' << m_attspe << '\t' << m_defspe;
    for(int i=0; i<4; i++)
    {
        save << '\t' << m_ct[i].getID();
    }
    save.close();
}


void Pokemon::recevoirDegat(int dmg)
{
    m_pv -= dmg;
    if (m_pv < 0)
    {
        m_pv = 0;
    }
}

void Pokemon::heal(int amnt)
{

    m_pv += amnt;
    if (m_pv > m_MaxPV)
    {
        m_pv = m_MaxPV;
    }

}

bool Pokemon::estVivant() const
{
    return m_pv > 0;
}


void Pokemon::addCT(Capacite ct)
{
    bool deja(false);
    for(int i=0; i<m_nbCT; i++)
    {
        if(m_ct[i].getID()==ct.getID())
        {
            deja = true;
            cout << m_name << " connait deja " << ct.getNom() << "!" << endl;
        }
    }
    if(!deja)
    {
        if(m_nbCT==4)
        {
            bool choix;
            cout << "Plus de place pour apprendre " << ct.getNom() << ".";
            cout << endl << "Oublier une capacite pour apprendre " << ct.getNom() << "?" << endl;
            cout << "oui 1 / non 0" << endl;
            cin >> choix;
            if(choix)
            {
                cout << "Quel capacite oublier?" << endl;
                for(int i=0; i<m_nbCT; i++)
                {
                    cout << m_ct[i].getNom() << '\t';
                }
                cout << "ANNULER (0)" << endl;
                int choix(0);
                cin >> choix;
                if(choix!=0)
                {
                    cout << m_name << " oubli " << m_ct[choix-1].getNom() << " et apprend " << ct.getNom() << "." << endl;
                    setCT(choix-1,ct);
                }
            }
            else
            {
                cout << m_name << " n'a pas appris " << ct.getNom() << "." << endl;
            }
        }
        else
        {
            cout << m_name << " a appris " << ct.getNom() << "!"<< endl;
            setNbCT(getNbCT() + 1);
            m_ct.push_back(ct);
        }
    }
}

void Pokemon::setCT(int i, Capacite ct)
{
    m_ct[i] = ct;
}

void Pokemon::gainExp(int exp)
{
    m_exp += exp;
    if(m_exp>=pow(m_niveau,3))
    {
        levelUP();
    }
}

void Pokemon::levelUP()
{
    m_exp -= pow(m_niveau,3);
    m_niveau++;
    cout << m_name << " passe au niveau " << m_niveau << "!" << endl;
}

void Pokemon::usePP(int a)
{
    m_ct[a].setPP(m_ct[a].getPP()-1);
}

string Pokemon::getName()
{
    return m_name;
}

Type Pokemon::getType()
{
    return m_type;
}

float Pokemon::getPV()
{
    return m_pv;
}

float Pokemon::getMaxPV()
{
    return m_MaxPV;
}

int Pokemon::getNiveau()
{
    return m_niveau;
}



Capacite Pokemon::getCT(int i)
{
    return m_ct[i];
}

int Pokemon::getAtt()
{
    return m_attaque;
}
int Pokemon::getDef()
{
    return m_defense;
}

int Pokemon::getNbCT()
{
    return m_nbCT;
}


int Pokemon::getExp()
{
    return m_exp;
}


int Pokemon::getNextLevelExpReq()
{
    return pow(m_niveau,3);
}

int Pokemon::getExpOnKill()
{
    return m_expOnKill;
}
