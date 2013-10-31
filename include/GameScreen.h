#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <vector>
#include "Screen.h"
#include "ElementUI.h"

class Engine;
class GameScreen : public Screen
{
    public:
        GameScreen(Engine *engine);
        virtual ~GameScreen();
        void show(SDL_Surface *screen);
        void render(SDL_Surface *screen);
        void resize(SDL_Surface *screen);
        void hide(SDL_Surface *screen);
        void event(SDL_Event *event, bool *loop);
        void mouseClick(int x, int y);

        /**************
        * Animations *
        **************/
        void swap_animation(ElementUI *s1, ElementUI *s2);

        Engine* getEngine();

    private:
        Engine *engine_; // moteur du jeu

        std::vector<ElementUI> elements_;

        SDL_Surface *panel_; // surface du panel (placée sur la gauche)
        SDL_Rect panel_form_; // caractéristiques du panel (sa forme, taille)

        SDL_Surface *grid_;
        SDL_Rect grid_form_;

        ElementUI *select_; // pointeur vers l'élément précédemment sélectionné

        bool redraw_; // booléen pour déterminer s'il y a nécessité de redessiner l'écran (évite l'usage du processeur pour rien)
};

#endif // GAMESCREEN_H
