#include "../include/PointBonusElement.h"
#include <iostream>
PointBonusElement::PointBonusElement(Element el): BaseElement(el)
{
    bonusMoney_ = 0;
    bonusValue_ = 3;
}

PointBonusElement::~PointBonusElement()
{
    //dtor
}

int PointBonusElement::getValue()
{
    std::cout << "+" << bonusValue_ << std::endl;
    return bonusValue_ + el_.getValue();
}

int PointBonusElement::getMoney()
{
    return bonusMoney_ + el_.getMoney();
}
