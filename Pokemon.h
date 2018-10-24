#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include "Inventaire.h"
#include "Capacite.h"
#include "Type.h"
#include <string>
#include <vector>
class Pokemon
{
public:
    Pokemon();
    Pokemon(std::string name,Type type,int niveau,float pv,int att,int def, int attspe, int defspe, int stade , bool canEvolve);
    void recevoirDegat(int dmg);
    void heal(int amnt);
    bool estVivant() const;
    void addCT(Capacite ct);
    void gainExp(int exp);
    std::string getName();
    Type getType();
    float getPV();
    void setPV(float val) { m_pv = val; }
    int getNiveau();
    void setNiveau(int val) { m_niveau = val; }
    int getAtt();
    int getDef();
    Capacite getCT(int i);
    void setCT(int i, Capacite ct);
    float getMaxPV();
    void savePokemon();
    int getNbCT();
    void setNbCT(int val) {m_nbCT = val;}
    void usePP(int a);
    int getExp();
    void setExp(float val) {m_exp = val;}
    int getNextLevelExpReq();
    int getExpOnKill();
    void levelUP();



private :
    std::string m_name;
    Type m_type;
    int m_numero;
    int m_niveau;
    float m_exp;
    int m_expOnKill;
    float m_pv;
    float m_MaxPV;
    int m_attaque;
    int m_defense;
    int m_attspe;
    int m_defspe;
    int m_precison;
    int m_evasion;
    int m_attNiv;
    int m_defNiv;
    int m_stade;
    bool m_canEvolve;
    int m_nbCT;
    std::vector<Capacite> m_ct;
};

#endif // POKEMON_H_INCLUDED
