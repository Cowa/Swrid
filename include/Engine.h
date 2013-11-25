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
   *  La classe Engine, moteur du jeu
   */
class Engine
{
    private:

    /*!
     *  \brief Constructeur
     *
     *  Constructeur privé de la classe Engine
     *
     *
     */
        Engine();
     /*!
     *  \brief surchage du constructeur
     *
     *  Surchage privé du constructeur de la classe Engine
     *  \param SDL_Surface, pointeur sur la SDL_surface
     *  \param SDl_event , pointeur sur SDL_event
     *  \param booléen, la boucle du jeux
     */
        Engine(SDL_Surface *sdlScreen, SDL_Event *event, bool *loop);

      /*!
     *  \brief Instance de engine static
     *
     */
        static Engine *engine_;
     /*!
     *  \brief  Attribut  grille
     *
     */
        Grid *grid_;
        /*************************
        * Les différents écrans *
        ************************/
        /*!
     *  \brief Attribut screen principal
     *
     */
        Screen *screen_; // l'écran courant
    /*!
     *  \brief Attribut écran du menu
     *
     */
        Screen *menuScreen_; // l'écran menu
    /*!
     *  \brief Attribut écran du jeux
     *
     */
        Screen *gameScreen_; // l'écran de jeu
        /*************
        * Le joueur *
        ************/
    /*!
     *  \brief Attribut playeur
     *
     */
        Player *player_;

        /*****************
        * Variables SDL *
        ****************/
    /*!
     *  \brief  Attribut SDL_event pour la gestion des événements
     *
     */
        SDL_Event *event_; // gestion des événements
    /*!
     *  \brief Attribut booléen la boucle du jeux
     *
     */
        bool *loop_; // booléen de la boucle principale
    /*!
     *  \brief Attribut SDL_Surface de l'écran principal
     *
     */
        SDL_Surface *sdlScreen_; // surface de l'écran principal

    public:

    /*!
     *  \brief Méthode du Singleton pour obtenir une seul instance de Engine
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
     *  Destructeur de la classe  Engine
     *
     *
     */
        virtual ~Engine();
    /*!
     *  \brief Initialisation de Engine
     *
     *  Méthode qui initialise les attributs de Engine
     *
     *
     */
        void init();

        void event();
        void render();
    /*!
     *  \brief Setteur de l'attribut screen l'écran principal
     *
     *  Méthode qui affecte le nouvelle écran principal au moteur
     *
     *
     */
        void setScreen(Screen *screen);
     /*!
     *  \brief Setteur de l'attribut gridMode
     *
     *  Méthode qui affecte le mode de jeux
     *
     *
     */
        void setGridMode(GridMode *gridMode);
     /*!
     *  \brief Accesseur de l'attribut gridMode
     *
     *  Méthode qui retourne la grille du jeux
     *
     *  \return Grid, la grille
     */
        Grid* getGrid();
    /*!
     *  \brief Accesseur de l'attribut screen
     *
     *  Méthode qui retourne l'écran courant
     *
     *  \return Screen , l'écran courant
     */
        Screen* getScreen();
    /*!
     *  \brief Accesseur de l'attribut SDlscreen
     *
     *  Méthode qui retourne la SDL_Surface
     *
     *  \return SDL_Surface , SDLscreen
     */
        SDL_Surface* getSDLscreen();
    /*!
     *  \brief Accesseur de l'attribut menuScreen
     *
     *  Méthode qui retourne l'attribut écran de menu
     *
     *  \return screen , l'écran du menu
     */
        Screen* getMenuScreen();

    /*!
     *  \brief Accesseur de l'attribut gameScreen
     *
     *  Méthode qui retourne l'attibut écran de jeux
     *
     *  \return screen , l'écran de jeux
     */
        Screen* getGameScreen();
    /*!
     *  \brief Setteur de l'attribut event
     *
     *  Méthode qui affecte la nouvelle valeur de event
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
