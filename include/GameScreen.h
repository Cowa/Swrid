#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <vector>
#include "Screen.h"
#include "ElementUI.h"
#include "Button.h"

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

        //SDL_Rect screen_old_;

        // Score
        SDL_Surface *score_;
        TTF_Font *score_font_;
        SDL_Color score_color_;
        SDL_Rect score_pos_;

        SDL_Rect score_clipper_;

        SDL_Surface *bg_; // surface du fond
        SDL_Surface *bg_opt_; // surface optimisée
        SDL_Rect bg_pos_; // position du fond

        SDL_Surface *el_img_; // surface de l'image des éléments
        SDL_Surface *el_img_opt_; // surface optimisée

        SDL_Rect top_grid_;
        SDL_Rect bottom_grid_;

        Button * buttonMenu_;


        SDL_Rect grid_form_; // caractéristiques de la grille où sont placés les éléments(forme, taille)
        SDL_Rect grid_clipper_; // défini la zone de clipping pour la grille + les extra

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
