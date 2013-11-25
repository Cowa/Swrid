#ifndef MENUSCREEN_H
#define MENUSCREEN_H
/**
 * \file MenuScreen.H
 * \brief  classe MenuScreen
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */
#include "Screen.h"
#include "Button.h"

class Engine;
/*! \class MenuScreen
   * \brief
   *
   *  La classe MenuScreen,
   *  Implémente l'interface Screen
   *
   */
class MenuScreen : public Screen
{
    public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe MenuScreen
     *  \param Engine, le moteur de jeu
     */
        MenuScreen(Engine *engine);
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe MenuScreen
     *
     */
        virtual ~MenuScreen();
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
     *  \brief methode qui retourne le pointeur sur le moteur du jeu
     *
     *
     *
     */
        Engine* getEngine();
    private:
        /*!
     *  \brief instance du singleton Engine
     *
     * attribut Engine le moteur du jeu
     *
     */
        Engine *engine_; // moteur du jeu
    /*!
     *  \brief
     *
     * attribut redraw
     *
     */
        bool redraw_;

        // Fond

    /*!
     *  \brief
     *
     * attribut de surface du fond d'écran
     *
     */
        SDL_Surface *bg_;
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
        SDL_Rect bg_pos_;

        // button normal mode
    /*!
     *  \brief
     *
     * attribut bouton de redirection vers le jeu en mode normal
     *
     */
        Button *bNormalMode_;
     /*!
     *  \brief
     *
     * attribut bouton , permettant de quitter le jeu
     *
     */
        Button *bQuit_;
     /*!
     *  \brief
     *
     * attribut bouton de redirection vers le jeu en mode difficile
     *
     */
        Button *bHardMode_;
};

#endif // MENUSCREEN_H
