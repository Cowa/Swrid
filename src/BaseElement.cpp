#include "../include/BaseElement.h"
#include <iostream>
BaseElement::BaseElement()
{
    Element el(NEUTRAL_ELEMENT);
    el_ = el;
    bonusValue_ = 0;
    bonusMoney_ = 0;
}

BaseElement::BaseElement(Element el)
{
    el_ = el;
    bonusValue_ = 0;
    bonusMoney_ = 0;
}

BaseElement::~BaseElement()
{
    //dtor
}

int BaseElement::getType()
{
    return el_.getType();
}

void BaseElement::setType(int type)
{
    el_.setType(type);
}

int BaseElement::getValue()
{
    return bonusValue_ + el_.getValue();
}

int BaseElement::getMoney()
{
    return bonusMoney_ + el_.getMoney();
}
