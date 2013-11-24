#include "../include/Button.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

Button::Button(int x,int y)
{
    state_ = NORMAL;

    buttonPosition_.x = x;
    buttonPosition_.y = y;
}

void Button::init(const char *path1, const char *path2)
{
    SDL_Surface *img = IMG_Load(path1);
    bNormal_ = SDL_DisplayFormatAlpha(img);
    SDL_FreeSurface(img);

    img = IMG_Load(path2);
    bHover_ = SDL_DisplayFormatAlpha(img);
    SDL_FreeSurface(img);
}

void Button::applyButton(SDL_Surface *surface)
{
    if(state_ == NORMAL)
        SDL_BlitSurface(bNormal_, NULL, surface, &buttonPosition_);
    else
        SDL_BlitSurface(bHover_, NULL, surface, &buttonPosition_);
}

bool Button::checkClick(int mouseX, int mouseY)
{
    return (buttonPosition_.x < mouseX && mouseX < buttonPosition_.x + bNormal_->w && buttonPosition_.y< mouseY && mouseY < buttonPosition_.y + bNormal_->h);
}

void Button::setState(int state)
{
    state_ = state;
}

void Button::free()
{
    SDL_FreeSurface(bNormal_);
    SDL_FreeSurface(bHover_);
}

Button::~Button()
{
}
