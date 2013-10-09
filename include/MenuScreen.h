#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "Screen.h"

class Engine;
class MenuScreen : public Screen
{
    public:
        MenuScreen(Engine *engine);
        virtual ~MenuScreen();
        void show(SDL_Surface *screen);
        void render(SDL_Surface *screen);
        void resize(SDL_Surface *screen);
        void hide(SDL_Surface *screen);
        void event(SDL_Event *event, bool *loop);
        void mouseClick(int x, int y);

        Engine* getEngine();
    private:
        Engine *engine_; // moteur du jeu

};

#endif // MENUSCREEN_H
