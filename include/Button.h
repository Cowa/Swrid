#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

const int NORMAL = 0;
const int HOVER = 1;

class Button
{
    public:
        Button(int x,int y);
        virtual ~Button();
        //SDL_Surface* GetbuttonSurface() { return buttonSurfaceOpt_; }
        //void SetbuttonSurface(SDL_Surface* val) { buttonSurface_ = val; }
        SDL_Rect GetbuttonPosition() { return buttonPosition_; }
        void SetbuttonPosition(SDL_Rect val) { buttonPosition_ = val; }
        void applyButton(SDL_Surface* surface);
        bool checkClick(int mouseX, int mouseY);
        void setState(int state);
        void free();
        void init(const char *path1, const char *path2);

    protected:

    private:
        int state_;
        SDL_Surface *bNormal_;
        SDL_Surface *bHover_;
        SDL_Rect buttonPosition_;
};

#endif // BUTTON_H
