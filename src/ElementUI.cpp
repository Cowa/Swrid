#include "../include/ElementUI.h"

ElementUI::ElementUI()
{
    gridx_ = 0, gridy_ = 0;
    form_.x = 0, form_.y = 0, form_.h = 5, form_.w = 5;
    type_ = NEUTRAL_ELEMENT;
}

ElementUI::ElementUI(SDL_Rect form, int x, int y, int type)
{
    form_ = form;
    gridx_ = x;
    gridy_ = y;
    type_ = type;
}

ElementUI::~ElementUI()
{
    //dtor
}

SDL_Rect ElementUI::getForm()
{
    return form_;
}

void ElementUI::draw(SDL_Surface *grid)
{
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
