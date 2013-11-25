#ifndef SCREEN_H
#define SCREEN_H
/**
 * \file Screen.H
 * \brief  classe Screen
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */
#include "Define.h"


/*! \class Screen
   * \brief
   *
   *  Interface Screen
   *
   *
   */
class Screen
{
    public:

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Screen
     */
        virtual ~Screen() {}
    /*!
     *  \brief methode show
     *
     *  methode permettant d'afficher l'écran ( appeler une fois )
     *
     *  \param SDl_Surface, l'écran
     */
        virtual void show(SDL_Surface *screen) = 0; // appelée seulement lorsqu'on entre dans l'écran
     /*!
     *  \brief methode render
     *
     * methode qui gère l'affichage de l'écran
     *
     *  \param SDl_Surface , l'écran
     */
        virtual void render(SDL_Surface *screen) = 0; // gère l'affichage de l'écran
     /*!
     *  \brief methode resize
     *
     * methode qui permet de redimensionner la taille de la fenêtre
     *
     *  \param SDl_Surface , l'écran a redimensionner
     */
        virtual void resize(SDL_Surface *screen) = 0; // appelée lors du show() et lorsque la fenêtre et redimensionnée
    /*!
     *  \brief methode hide
     *
     * methode qui "cache" l'écran
     *
     * \param SDl_Surface
     */
        virtual void hide(SDL_Surface *screen) = 0; // appelée lorsqu'on quitte l'écran
     /*!
     *  \brief methode event
     *
     * methode qui gère l'ensemble des événements liés à l'écran
     *
     *  \param SDL_Event, l'évenement sdl
     *  \param booléen, la boucle
     */
        virtual void event(SDL_Event *event, bool *loop) = 0; // gère l'ensemble des événements liés à l'écran
     /*!
     *  \brief methode mouseClick
     *
     * methode qui permet la gestion du clique sur l'écran
     *
     *  \param entier, l'abscisse
     *  \param entier, l'ordonnée
     */
        virtual void mouseClick(int x, int y) = 0; // gère l'événement du clic de souris
};

#endif // SCREEN_H
