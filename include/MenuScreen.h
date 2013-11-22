#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "Screen.h"
#include "Button.h"

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
        bool redraw_;

        // Fond
        SDL_Surface *bg_;
        SDL_Surface *bg_opt_; // surface optimisée
        SDL_Rect bg_pos_;

        // button normal mode
        Button * bNormalMode_;
        Button * bQuit_;
        Button * bHardMode_;
};

#endif // MENUSCREEN_H
