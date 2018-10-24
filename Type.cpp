#include "Type.h"
#include <iostream>
#include <string>
using namespace std;

Type::Type() : m_nom("NORMAL"), m_nbtype(1)
{
}

string types[18] = {"NORMAL","COMBAT","VOL","POISON","SOL","ROCHE","INSECT","SPECTRE","ACIER","FEU","EAU","PLANTE","ELECTR","PSY","GLACE","DRAGON","TENEBRE","FEE"};
//                     0        1       2       3       4     5        6        7         8     9     10      11      12      13     14      15        16      17
Type::Type(int nb) : m_nbtype(nb)
{
    m_nom= types[nb];
}

