#include "../include/Element.h"


Element::Element()
{
    type_ = NEUTRAL_ELEMENT;
    value_ = VALUE_ELEMENT;
    money_ = MONEY_ELEMENT;
}

Element::Element(int type)
{
    value_ = VALUE_ELEMENT;
    money_ = MONEY_ELEMENT;
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

    value_ = VALUE_ELEMENT;
    money_ = MONEY_ELEMENT;
}

Element::~Element(){}

int Element::getMoney()
{
    return money_;
}

int Element::getValue()
{
    return value_;
}

int Element::getType()
{
    return type_;
}

void Element::setType(int type)
{
    type_ = type;
}
