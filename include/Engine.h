#ifndef ENGINE_H
#define ENGINE_H
/**
 * \file Engine.H
 * \brief  classe Engine
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */
#include "Grid.h"
#include "Screen.h"
#include "Define.h"
#include "MenuScreen.h"
#include "GameScreen.h"
#include "Player.h"
/*! \class Engine
   * \brief
   *
   *  La classe Engine, moteur du jeux
   */
class Engine
{
    private:

    /*!
     *  \brief Constructeur
     *
     *  Constructeur privé de la classe engine
     *
     *
     */
        Engine();
     /*!
     *  \brief surchage du constructeur
     *
     *  surchage privé du constructeur de la classe Engine
     *  \param SDL_Surface, pointeur sur la SDL_surface
     *  \param SDl_event , pointeur sur SDL_event
     *  \param booléen, la boucle du jeux
     */
        Engine(SDL_Surface *sdlScreen, SDL_Event *event, bool *loop);
      /*!
     *  \brief instance de engine static
     *
     */
        static Engine *engine_;
     /*!
     *  \brief  attribut  grille
     *
     */
        Grid *grid_;
        /*************************
        * Les différents écrans *
        ************************/
        /*!
     *  \brief attribut screen principal
     *
     */
        Screen *screen_; // l'écran courant
    /*!
     *  \brief attribut écran du menu
     *
     */
        Screen *menuScreen_; // l'écran menu
    /*!
     *  \brief attribut écran du jeux
     *
     */
        Screen *gameScreen_; // l'écran de jeu
        /*************
        * Le joueur *
        ************/
    /*!
     *  \brief attribut playeur
     *
     */
        Player *player_;

        /*****************
        * Variables SDL *
        ****************/
    /*!
     *  \brief  attribut SDL_event pour la gestion des événements
     *
     */
        SDL_Event *event_; // gestion des événements
    /*!
     *  \brief attribut booléen la boucle du jeux
     *
     */
        bool *loop_; // booléen de la boucle principale
    /*!
     *  \brief attribut SDL_Surface de l'écran principal
     *
     */
        SDL_Surface *sdlScreen_; // surface de l'écran principal

    public:

    /*!
     *  \brief methode du Singleton pour obtenir une seul instance de Engine
     *  \return Engine l'instance de la classe
     */
        static Engine* getInstance()
        {
            if(!engine_)
                engine_ = new Engine();
            return engine_;
        }

    /*!
     *  \brief Destructeur
     *
     *  destructeur de la classe  Engine
     *
     *
     */
        virtual ~Engine();
    /*!
     *  \brief initialisation de Engine
     *
     *  méthode qui initialise les attributs de Engine
     *
     *
     */
        void init();

        void event();
        void render();
    /*!
     *  \brief setteur de l'attribut screen l'écran principal
     *
     *  méthode qui affecte le nouvelle écran principal au moteur
     *
     *
     */
        void setScreen(Screen *screen);
     /*!
     *  \brief setteur de l'attribut gridMode
     *
     *  méthode qui affecte le mode de jeux
     *
     *
     */
        void setGridMode(GridMode *gridMode);
     /*!
     *  \brief accesseur de l'attribut gridMode
     *
     *  méthode qui retourne la grille du jeux
     *
     *  \return Grid , la grille
     */
        Grid* getGrid();
    /*!
     *  \brief accesseur de l'attribut screen
     *
     *  méthode qui retourne l'écran courant
     *
     *  \return Screen , l'écran courant
     */
        Screen* getScreen();
    /*!
     *  \brief accesseur de l'attribut SDlscreen
     *
     *  méthode qui retourne la SDL_Surface
     *
     *  \return SDL_Surface , SDLscreen
     */
        SDL_Surface* getSDLscreen();
    /*!
     *  \brief accesseur de l'attribut menuScreen
     *
     *  méthode qui retourne l'attribut écran de menu
     *
     *  \return screen , l'écran du menu
     */
        Screen* getMenuScreen();

    /*!
     *  \brief accesseur de l'attribut gameScreen
     *
     *  méthode qui retourne l'attibut écran de jeux
     *
     *  \return screen , l'écran de jeux
     */
        Screen* getGameScreen();
    /*!
     *  \brief setteur de l'attribut event
     *
     *  méthode qui affecte la nouvelle valeur de event
     *
     *
     */
        void setEvent(SDL_Event *event);
    /*!
     *  \brief setteur de l'attribut Loop
     *
     *  méthode qui affecte la nouvelle valeur de la boucle de jeux
     *
     *
     */
        void setLoop(bool *loop);
    /*!
     *  \brief setteur de l'attribut SDLscreen
     *
     *  méthode qui affecte la nouvelle valeur de SDLscreen
     *
     *  \return screen , l'écran de jeux
     */
        void setSDLscreen(SDL_Surface *newScreen);
};

#endif // ENGINE_H
