#ifndef ELEMENT_H
#define ELEMENT_H

#include <cstdlib>

// Type de l'élément neutre
const int NEUTRAL_ELEMENT = 0;
const int VALUE_ELEMENT = 3;
const int MONEY_ELEMENT = 0;

class Element
{
public:
    Element();
    Element(int type);
    Element(bool random, int n_el);
    ~Element();

    int getValue();
    int getMoney();
    int getType();
    void setType(int type);

protected:
    int type_;
    int value_; //valeur de l'élément (nb de points qu'il va donner lors de sa suppression)
    int money_; //argent récupéré lors de sa suppression
};

#endif // ELEMENT_H
