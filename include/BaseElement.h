#ifndef ELEMENTOPTION_H
#define ELEMENTOPTION_H

#include "Element.h"

class BaseElement: public Element
{
    public:
        BaseElement();
        BaseElement(Element el);
        virtual ~BaseElement();

        int getValue();
        int getMoney();
        int getType();
        void setType(int type);
    private:
    protected:
        Element el_;
        int bonusValue_;
        int bonusMoney_;
};

#endif // ELEMENTOPTION_H
