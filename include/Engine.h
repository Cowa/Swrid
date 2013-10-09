#ifndef ENGINE_H
#define ENGINE_H

#include "Grid.h"
#include "Screen.h"
#include "Define.h"
#include "MenuScreen.h"
#include "GameScreen.h"

class Engine
{
    private:
        Grid *grid_;
        /*************************
        * Les différents écrans *
        ************************/
        Screen *screen_; // l'écran courant
        Screen *menuScreen_; // l'écran menu
        Screen *gameScreen_; // l'écran de jeu
        SDL_Event *event_; // gestion des événements
        bool *loop_;

        SDL_Surface *sdlScreen_;
    public:
        Engine(SDL_Surface *sdlScreen, SDL_Event *event, bool *loop);
        virtual ~Engine();

        void init();
        void event();
        void render();
        void setScreen(Screen *screen);

        Grid* getGrid();
        Screen* getScreen();
        SDL_Surface* getSDLscreen();
        void setSDLscreen(SDL_Surface *newScreen);
        Screen* getMenuScreen();
        Screen* getGameScreen();
};

#endif // ENGINE_H
