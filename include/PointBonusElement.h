#ifndef OPTIONVALUE_H
#define OPTIONVALUE_H

#include "BaseElement.h"

class PointBonusElement : public BaseElement
{
    public:
        PointBonusElement(Element el);
        virtual ~PointBonusElement();

        int getValue();
        int getMoney();
    protected:
};

#endif // OPTIONVALUE_H
