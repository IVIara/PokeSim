#include "Combat.h"
#include "Pokemon.h"
#include <iostream>
#include <string>

using namespace std;

double elements[18][18] =
{
    /*NORMAL*/             {1,1,1,1,1,0.5,1,0,0.5,1,1,1,1,1,1,1,1,1},
    /*COMBAT*/             {2,1,0.5,0.5,1,2,0.5,0,2,1,1,1,1,0.5,2,1,2,0.5},
    /*VOL*/                {1,2,1,1,1,0.5,2,1,0.5,1,1,2,0.5,1,1,1,1,1},
    /*POISON*/             {1,1,1,0.5,0.5,0.5,1,0.5,0,1,1,2,1,1,1,1,1,2},
    /*SOL*/                {1,1,0,2,1,2,0.5,1,2,2,1,0.5,2,1,1,1,1,1},
    /*ROCHE*/              {1,0.5,2,1,0.5,1,2,1,0.5,2,1,1,1,1,2,1,1,1},
    /*INSECT*/             {1,0.5,0.5,0.5,1,1,1,0.5,0.5,0.5,1,2,1,2,1,1,2,0.5},
    /*SPECTRE*/            {0,1,1,1,1,1,1,2,1,1,1,1,1,2,1,1,0.5,1},
    /*ACIER*/              {1,1,1,1,1,2,1,1,0.5,0.5,0.5,1,0.5,1,2,1,1,2},
    /*FEU*/                {1,1,1,1,1,0.5,2,1,2,0.5,0.5,2,1,1,2,0.5,1,1},
    /*EAU*/                {1,1,1,1,2,2,1,1,1,2,0.5,0.5,1,1,1,0.5,1,1},
    /*PLANTE*/             {1,1,0.5,0.5,2,2,0.5,1,0.5,0.5,2,0.5,1,1,1,0.5,1,1},
    /*ELECTR*/             {1,1,2,1,0,1,1,1,1,1,2,0.5,0.5,1,1,0.5,1,1},
    /*PSY*/                {1,2,1,2,1,1,1,1,0.5,1,1,1,1,0.5,1,1,0,1},
    /*GLACE*/              {1,1,2,1,2,1,1,1,0.5,0.5,0.5,2,1,1,0.5,2,1,1},
    /*DRAGON*/             {1,1,1,1,1,1,1,1,0.5,1,1,1,1,1,1,2,1,0},
    /*TENEBRE*/            {1,0.5,1,1,1,1,1,2,1,1,1,1,1,2,1,1,0.5,0.5},
    /*FEE*/                {1,2,1,0.5,1,1,1,1,0.5,0.5,1,1,1,1,1,2,2,1}
};


Combat::Combat(Dresseur a,Dresseur b) : m_att(a), m_def(b)
{
}

void Combat::affiche()
{
    int vieATT(0);
    int vieDEF(0);
    //int Jexp(0);
    while(m_att.getPokemon(0).getPV()>0 && m_def.getPokemon(0).getPV()>0)
    {

        for(int i=0; i<((120-(int)m_def.getPokemon(0).getName().size())/9)+1; i++)
        {
            cout << '\t';
        }
        cout << m_def.getPokemon(0).getName() << endl;
        for(int i=0; i<13; i++)
        {
            cout << '\t';
        }
        vieDEF= ((m_def.getPokemon(0).getPV()/m_def.getPokemon(0).getMaxPV())*10);
        cout << "pv : ";
        for(int i=0; i<vieDEF; i++)
        {
            cout << "=";
        }
        for(int i=0; i<-(vieDEF-10); i++)
        {
            cout << "-";
        }
        cout << endl;


        cout << m_att.getPokemon(0).getName() << endl;
        vieATT= ((m_att.getPokemon(0).getPV()/m_att.getPokemon(0).getMaxPV())*10);
        for(int i=0; i<vieATT; i++)
        {
            cout << "=";
        }
        for(int i=0; i<-(vieATT-10); i++)
        {
            cout << "-";
        }
        cout << endl;
        cout << "pv :" << m_att.getPokemon(0).getPV() << "/" << m_att.getPokemon(0).getMaxPV() << endl;

//        Jexp = m_att.getPokemon(0).getExp()*10/m_att.getPokemon(0).getNextLevelExpReq();
//        for(int i=0;i<Jexp; i++)
//        {
//            cout << "=";
//        }
//        for(int i=0;i<-Jexp+10;i++)
//        {
//            cout << "-";
//        }
//        cout << endl;

        int choix(0);
        cout << "Attaque  | Objets" << endl;
        do
        {
            cin >> choix;
        }
        while(choix>2 || choix<1);
        if(choix==2)
        {
            if (!m_att.objets())
            {
                attaque();
            }
        }
        else
        {
            attaque();

        }

        turn();
        cout << endl << "------------------------------------------------------------------------------------------------------------------" << endl << endl;

    }
    fin();
}


void Combat::attaque()
{
    int choix(0);
    do
    {
        for(int i=0; i<4; i++)
        {
            if(i<m_att.getPokemon(0).getNbCT())
            {
                cout << m_att.getPokemon(0).getCT(i).getNom() << "(" << m_att.getPokemon(0).getCT(i).getPP() << ")" <<'\t' ;
            }
            else
            {
                cout << "vide" << '\t';
            }
        }
        cout << endl;
        cin >> choix;
    }
    while(choix<1 || choix > m_att.getPokemon(0).getNbCT());
    if (m_att.getPokemon(0).getCT(choix-1).getPP()>0)
    {
        m_att.getPokemon(0).usePP(choix-1);
        int dmg(1);
        double stab(1);
        double ele = elements[m_att.getPokemon(0).getCT(choix-1).getType().Getm_nbtype()][m_def.getPokemon(0).getType().Getm_nbtype()];
        int pow = m_att.getPokemon(0).getCT(choix-1).getPower();
        if(m_att.getPokemon(0).getType().Getm_nbtype() == m_att.getPokemon(0).getCT(choix-1).getType().Getm_nbtype())
        {
            stab = 1.5;
        }
        dmg = (((((2*m_att.getPokemon(0).getNiveau())/5)*pow*m_att.getPokemon(0).getAtt()/m_def.getPokemon(0).getDef())/50)+2)*stab*ele;
        m_def.getPokemon(0).recevoirDegat(dmg);
        cout << m_att.getPokemon(0).getName() << " utilise " << m_att.getPokemon(0).getCT(choix-1).getNom() << "!" << endl;
        if(ele>1)
        {
            cout << "C'est super efficace !" << endl;
        }
        else if (ele==0)
        {
            cout << m_def.getPokemon(0).getName() << " n'est pas affecté !" << endl;
        }
        else if (ele<1)
        {
            cout << "Ce n'est pas tres efficace..." << endl;
        }
    }
    else
    {
        cout << "Pas assez de PP" << endl;
    }
}




void Combat::turn()
{
    Dresseur c;
    c = m_att;
    m_att = m_def;
    m_def = c;
}


void Combat::fin()
{
    if(m_att.getPokemon(0).estVivant())
    {
        cout << endl<< endl<<endl;
        cout << m_def.getPokemon(0).getName() << " est K.O !" << endl;
        cout << m_att.getName() << " a vaincu " << m_def.getName() << endl;
        cout << m_att.getPokemon(0).getName() << " gagne " << m_def.getPokemon(0).getExpOnKill()*m_def.getPokemon(0).getNiveau()/7 << "exp !" << endl;
        m_att.getPokemon(0).gainExp(m_def.getPokemon(0).getExpOnKill()*m_def.getPokemon(0).getNiveau()/7);
    }
    else
    {
        cout << endl<< endl<<endl;
        cout << m_att.getPokemon(0).getName() << " est K.O !" << endl;
        cout << m_def.getName() << " a vaincu " << m_att.getName() << endl;
        cout << m_def.getPokemon(0).getName() << " gagne " << m_att.getPokemon(0).getExpOnKill()*m_att.getPokemon(0).getNiveau()/7 << "exp !" << endl;
        m_def.getPokemon(0).gainExp(m_att.getPokemon(0).getExpOnKill()*m_att.getPokemon(0).getNiveau()/7);
    }
    //m_att.savePokemon();
}


