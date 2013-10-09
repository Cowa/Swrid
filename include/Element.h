#ifndef ELEMENT_H
#define ELEMENT_H

#include <cstdlib>

// Type de l'élément neutre
const int NEUTRAL_ELEMENT = 0;

class Element
{
public:
    Element();
    Element(int type);
    Element(bool random, int n_el);
    ~Element();

    int getType();
    void setType(int type);

private:
    int type_;
};

#endif // ELEMENT_H
