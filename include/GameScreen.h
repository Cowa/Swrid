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

        void updateElements(); // MAJ des ElementUI
        void setElementsToBePush(); // Prépare les ElementUI à être push
        void setElementsToBePull(); // Prépare les ElementUI à subir la gravité

        Engine* getEngine();

    private:
        Engine *engine_; // moteur du jeu

        std::vector<ElementUI> elements_;
        int col_w_; // largeur colonne
        int row_h_; // hauteur ligne
        int n_rows_;
        int n_cols_;

        /*
        SDL_Surface *panel_; // surface du panel
        SDL_Rect panel_form_; // caractéristiques du panel (forme, taille)
        */
        // Score
        SDL_Surface *score_;
        TTF_Font *score_font_;
        SDL_Color score_color_;
        SDL_Rect score_pos_;

        SDL_Surface *bg_;
        SDL_Rect bg_pos_;

        SDL_Surface *grid_; // surface de la grille
        SDL_Rect grid_form_; // caractéristiques de la grille (forme, taille)

        ElementUI *select_; // pointeur vers l'élément précédemment sélectionné
        ElementUI *swapping_; // pointeur vers l'élément entrain d'être swappé

        bool swapped_; // si un swap a eu lieu
        bool purged_; // si une suppression a eu lieu
        bool animation_swap_; // booléen pour déterminer si une animation du swap est en cours
        bool animation_push_; // booléen pour déterminer si une animation du push est en cours
        bool animation_fall_;
        bool redraw_; // booléen pour déterminer s'il y a nécessité de redessiner l'écran (évite l'usage du processeur pour rien)
};

#endif // GAMESCREEN_H
