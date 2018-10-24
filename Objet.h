#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include <string>

class Objet
{
public :
    Objet();
    Objet(int id);
    std::string getNom();
    int getHeal();
    int getID();
    bool getAtt();
    bool getDef();

private :
    std::string m_nom;
    int m_id;
    int m_heal;
    bool m_att;
    bool m_def;
};
#endif // OBJET_H_INCLUDED
