#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Button
{
    public:
        Button(int x,int y,const char * path);
        virtual ~Button();
        SDL_Surface* GetbuttonSurface() { return buttonSurface_; }
        void SetbuttonSurface(SDL_Surface* val) { buttonSurface_ = val; }
        SDL_Rect GetbuttonPosition() { return buttonPosition_; }
        void SetbuttonPosition(SDL_Rect val) { buttonPosition_ = val; }
        void applyButton(SDL_Surface* surface);
        void setPathImg(const char* path);
        bool checkClick(int mouseX, int mouseY);
        void freeButtonSurface();

    protected:

    private:
        SDL_Surface* buttonSurface_;
        SDL_Surface* buttonSurfaceOpt_;
        SDL_Rect buttonPosition_;
};

#endif // BUTTON_H
