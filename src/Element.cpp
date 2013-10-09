#include "../include/Element.h"

Element::Element()
{
    type_ = NEUTRAL_ELEMENT;
}

Element::Element(int type)
{
    type_ = type;
}

Element::Element(bool random, int n_el)
{
    if(random)
    {
        type_ = (rand() % n_el) + 1;
    }
    else
        type_ = NEUTRAL_ELEMENT;
}

Element::~Element(){}

int Element::getType()
{
    return type_;
}

void Element::setType(int type)
{
    type_ = type;
}
