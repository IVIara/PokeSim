#ifndef TYPE_H
#define TYPE_H
#include <string>
#include <iostream>


class Type
{
    public:
        Type();
        Type(int nb);

        std::string Getm_nom() { return m_nom; }
        int Getm_nbtype() { return m_nbtype; }

    protected:

    private:
        std::string m_nom;
        int m_nbtype;
};

#endif // TYPE_H
