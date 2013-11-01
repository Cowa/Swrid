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
        bool redraw_;
        // Titre général
        SDL_Surface *title_;
        TTF_Font *title_font_;
        SDL_Color title_color_;
        SDL_Rect title_pos_;
};

#endif // MENUSCREEN_H
