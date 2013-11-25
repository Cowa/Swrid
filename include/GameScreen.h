#ifndef GAMESCREEN_H
#define GAMESCREEN_H
/**
 * \file GameScreen.H
 * \brief  classe GameScreen
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */
#include <vector>
#include "Screen.h"
#include "ElementUI.h"
#include "Button.h"
/*! \class GameScreen
   * \brief
   *
   *  La classe GameScreen, gestion de l'écran de jeux
   *  implémente l'interface Screen
   */
class Engine;
class GameScreen : public Screen
{
    public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe GameScreen
     *  \param Engine , le moteur du jeux
     *
     */
        GameScreen(Engine *engine);
     /*!
     *  \brief Destructeur
     *
     * Destructeur de la classe GameScreen
     *
     *
     */
        virtual ~GameScreen();

     /*!
     *  \brief methode show
     *
     *  methode permettant d'afficher l'écran ( appeler une fois )
     *
     *  \param SDl_Surface, l'écran
     */
        void show(SDL_Surface *screen);
    /*!
     *  \brief methode render
     *
     * methode qui gère l'affichage de l'écran
     *
     *  \param SDl_Surface , l'écran
     */
        void render(SDL_Surface *screen);
     /*!
     *  \brief methode resize
     *
     * methode qui permet de redimensionner la taille de la fenêtre
     *
     *  \param SDl_Surface , l'écran a redimensionner
     */
        void resize(SDL_Surface *screen);
     /*!
     *  \brief methode hide
     *
     * methode qui "cache" l'écran
     *
     * \param SDl_Surface
     */
        void hide(SDL_Surface *screen);
    /*!
     *  \brief methode event
     *
     * methode qui gère l'ensemble des événements liés à l'écran
     *
     *  \param SDL_Event, l'évenement sdl
     *  \param booléen, la boucle
     */
        void event(SDL_Event *event, bool *loop);

     /*!
     *  \brief methode mouseClick
     *
     * methode qui permet la gestion du clique sur l'écran
     *
     *  \param entier, l'abscisse
     *  \param entier, l'ordonnée
     */
        void mouseClick(int x, int y);
     /*!
     *  \brief methode updateElements
     *
     * methode de mise à jour des éléments
     *
     */
        void updateElements(); // MAJ des ElementUI
     /*!
     *  \brief methode setElementsToBePush
     *
     * methode de préparation des éléments a être push
     *
     */
        void setElementsToBePush(); // Prépare les ElementUI à être push

    /*!
     *  \brief methode setElementsToBePull
     *
     * methode de préparation des éléments à subir la gravité
     *
     */
        void setElementsToBePull(); // Prépare les ElementUI à subir la gravité

      /*!
     *  \brief instance du singleton Engine
     *
     *
     *
     */
        Engine* getEngine();

    private:

    /*!
     *  \brief instance du singleton Engine
     *
     * attribut Engine le moteur du jeux
     *
     */
        Engine *engine_; // moteur du jeu
    /*!
     *  \brief
     *
     * attribut elements, liste d'élements
     *
     */
        std::vector<ElementUI> elements_;

    /*!
     *  \brief
     *
     * attribut de largeur de colonne
     *
     */

        int col_w_; // largeur colonne
    /*!
     *  \brief
     *
     * attribut de hauteur de ligne
     *
     */
        int row_h_; // hauteur ligne
    /*!
     *  \brief
     *
     * attribut de nombre de ligne
     *
     */
        int n_rows_;
    /*!
     *  \brief
     *
     * attribut de nombre  de colonne
     *
     */
        int n_cols_;

        //SDL_Rect screen_old_;

        // Score
     /*!
     *  \brief
     *
     * attribut SDL_Surface la surface du score
     *
     */
        SDL_Surface *score_;
    /*!
     *  \brief
     *
     * attribut de la police du score
     *
     */
        TTF_Font *score_font_;
     /*!
     *  \brief
     *
     * attribut de la couleur de la  police du score
     *
     */
        SDL_Color score_color_;
    /*!
     *  \brief
     *
     * attribut de position de la  police du score
     *
     */
        SDL_Rect score_pos_;

     /*!
     *  \brief
     *
     * attribut clipper de la police du score
     *
     */
        SDL_Rect score_clipper_;

    /*!
     *  \brief
     *
     * attribut de surface du fond d'écran
     *
     */
        SDL_Surface *bg_; // surface du fond
    /*!
     *  \brief
     *
     * attribut de surface du fond d'écran
     * optimisée
     */
        SDL_Surface *bg_opt_; // surface optimisée
      /*!
     *  \brief
     *
     * attribut de position du fond d'écran
     *
     */
        SDL_Rect bg_pos_; // position du fond
      /*!
     *  \brief
     *
     * attribut de surface de l'image des éléments
     *
     */
        SDL_Surface *el_img_; // surface de l'image des éléments
    /*!
     *  \brief
     *
     * attribut de surface de l'image des éléments optimisée
     *
     */
        SDL_Surface *el_img_opt_; // surface optimisée

    /*!
     *  \brief
     *
     * attribut de surface du haut de la grille
     *
     */
        SDL_Rect top_grid_;
      /*!
     *  \brief
     *
     * attribut de surface du bas de la grille
     *
     */
        SDL_Rect bottom_grid_;

      /*!
     *  \brief
     *
     * attribut bouton de redirection vers le menu du jeux
     *
     */
        Button * buttonMenu_;

      /*!
     *  \brief
     *
     * caractéristiques de la grille où sont placés les éléments(forme, taille)
     *
     */
        SDL_Rect grid_form_; // caractéristiques de la grille où sont placés les éléments(forme, taille)
      /*!
     *  \brief
     *
     * défini la zone de clipping pour la grille + les extra
     *
     */
        SDL_Rect grid_clipper_; // défini la zone de clipping pour la grille + les extra
     /*!
     *  \brief
     *
     * pointeur vers l'élément précédemment sélectionné
     *
     */
        ElementUI *select_; // pointeur vers l'élément précédemment sélectionné
      /*!
     *  \brief
     *
     * pointeur vers l'élément entrain d'être swappé
     *
     */
        ElementUI *swapping_; // pointeur vers l'élément entrain d'être swappé
      /*!
     *  \brief
     *
     * booléen si un swap d'éléments a eu lieu
     *
     */
        bool swapped_; // si un swap a eu lieu
     /*!
     *  \brief
     *
     * booléen si une suppression d'éléments a eu lieu
     *
     */
        bool purged_; // si une suppression a eu lieu
     /*!
     *  \brief
     *
     * booléen pour déterminer si une animation du swap est en cours
     *
     */
        bool animation_swap_; // booléen pour déterminer si une animation du swap est en cours
     /*!
     *  \brief
     *
     * booléen pour déterminer si une animation du push est en cours
     *
     */
        bool animation_push_; // booléen pour déterminer si une animation du push est en cours
    /*!
     *  \brief
     *
     * booléen pour déterminer si une animation d'éléments qui tombe est en cours
     *
     */
        bool animation_fall_;
    /*!
     *  \brief
     *
     *booléen pour déterminer s'il y a nécessité de redessiner l'écran (évite l'usage du processeur pour rien)
     *
     */
        bool redraw_; // booléen pour déterminer s'il y a nécessité de redessiner l'écran (évite l'usage du processeur pour rien)
};

#endif // GAMESCREEN_H
