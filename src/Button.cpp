#include "../include/Button.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

Button::Button(int x,int y,const char * path)
{
    buttonSurface_= IMG_Load(path);
    buttonSurfaceOpt_=SDL_DisplayFormatAlpha(buttonSurface_);
    buttonPosition_.x=x;
    buttonPosition_.y=y;
}


void Button::applyButton(SDL_Surface* surface)
{

  SDL_BlitSurface(this->buttonSurfaceOpt_, NULL, surface, &this->buttonPosition_);

}

void Button::setPathImg(const char* path){
    SDL_FreeSurface(this->buttonSurface_);
    this->buttonSurface_=IMG_Load(path);
    buttonSurfaceOpt_=SDL_DisplayFormatAlpha(this->buttonSurface_);
}

bool Button::checkClick(int mouseX, int mouseY)
{
    if(this->buttonPosition_.x < mouseX && mouseX < this->buttonPosition_.x + this->buttonSurface_->w &&
    this->buttonPosition_.y< mouseY && mouseY < this->buttonPosition_.y + this->buttonSurface_->h)
    {return true; }
    else return false;
}

void Button::freeButtonSurface(){

SDL_FreeSurface(this->buttonSurface_);
}


Button::~Button()
{
    //dtor
}
