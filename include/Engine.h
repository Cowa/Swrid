#ifndef ENGINE_H
#define ENGINE_H

#include "Grid.h"
#include "Screen.h"
#include "Define.h"
#include "MenuScreen.h"
#include "GameScreen.h"
#include "Player.h"

class Engine
{
    private:
        Engine();
        Engine(SDL_Surface *sdlScreen, SDL_Event *event, bool *loop);

        static Engine *engine_;

        Grid *grid_;
        /*************************
        * Les différents écrans *
        ************************/
        Screen *screen_; // l'écran courant
        Screen *menuScreen_; // l'écran menu
        Screen *gameScreen_; // l'écran de jeu
        /*************
        * Le joueur *
        ************/
        Player *player_;

        /*****************
        * Variables SDL *
        ****************/
        SDL_Event *event_; // gestion des événements
        bool *loop_; // booléen de la boucle principale
        SDL_Surface *sdlScreen_; // surface de l'écran principal

    public:
        static Engine* getInstance()
        {
            if(!engine_)
                engine_ = new Engine();
            return engine_;
        }

        virtual ~Engine();

        void init();
        void event();
        void render();
        void setScreen(Screen *screen);
        void setGridMode(GridMode *gridMode);

        Grid* getGrid();
        Screen* getScreen();
        SDL_Surface* getSDLscreen();
        Screen* getMenuScreen();
        Screen* getGameScreen();

        void setEvent(SDL_Event *event);
        void setLoop(bool *loop);
        void setSDLscreen(SDL_Surface *newScreen);
};

#endif // ENGINE_H
