#include "../include/ElementUI.h"

ElementUI::ElementUI()
{
    gridx_ = 0, gridy_ = 0;
    velx_ = 0, vely_ = 0;
    destx_ = 0, desty_ = 0;
    form_.x = 0, form_.y = 0, form_.h = 5, form_.w = 5;
    type_ = NEUTRAL_ELEMENT;
}

ElementUI::ElementUI(SDL_Rect form, int x, int y, int type)
{
    form_ = form;
    gridx_ = x;
    gridy_ = y;
    velx_ = 0, vely_ = 0;
    destx_ = 0, desty_ = 0;
    type_ = type;
}

ElementUI::~ElementUI()
{
    //dtor
}

void ElementUI::draw(SDL_Surface *grid)
{
    form_.x += velx_;
    form_.y += vely_;

    if(type_ != NEUTRAL_ELEMENT)
    {
        int r = (type_*25)%255, g = (type_*50)%255, b = (type_*100)%255; // on tire des couleurs en fonction du type
        filledEllipseRGBA(grid, form_.x + (form_.w/2), form_.y + (form_.h/2), (form_.w/2)*0.75, (form_.h/2)*0.75, r, g, b, 255);
    }
}

bool ElementUI::isOn(int x, int y)
{
    return ( (type_ != NEUTRAL_ELEMENT) && (x>form_.x)&&(x<form_.x+form_.w)&&(y>form_.y)&&(y<form_.y+form_.h));
}

bool ElementUI::atDestination()
{
    if((getVelX() == 0 && getVelY() == 0) || ((getVelX()>0 && getForm().x >= getDestX()) || (getVelX()<0 && getForm().x <= getDestX()) || (getVelY()>0 && getForm().y >= getDestY()) || (getVelY()<0 && getForm().y <= getDestY())))
    {
        setVelX(0);
        setVelY(0);
        return true;
    }
    return false;
}

/**********
* GETTERS *
**********/
SDL_Rect ElementUI::getForm()
{
    return form_;
}

int ElementUI::getX()
{
    return gridx_;
}

int ElementUI::getY()
{
    return gridy_;
}

int ElementUI::getType()
{
    return type_;
}

int ElementUI::getVelX()
{
    return velx_;
}

int ElementUI::getVelY()
{
    return vely_;
}

int ElementUI::getDestX()
{
    return destx_;
}

int ElementUI::getDestY()
{
    return desty_;
}

/**********
* SETTERS *
**********/
void ElementUI::setX(int x)
{
    gridx_ = x;
}

void ElementUI::setY(int y)
{
    gridy_ = y;
}

void ElementUI::setType(int type)
{
    type_ = type;
}

void ElementUI::setForm(SDL_Rect form)
{
    form_ = form;
}

void ElementUI::setFormX(int x)
{
    form_.x = x;
}

void ElementUI::setFormY(int y)
{
    form_.y = y;
}

void ElementUI::setVelX(int x)
{
    velx_ = x;
}
void ElementUI::setVelY(int y)
{
    vely_ = y;
}

void ElementUI::setDestX(int x)
{
    destx_ = x;
}
void ElementUI::setDestY(int y)
{
    desty_ = y;
}
