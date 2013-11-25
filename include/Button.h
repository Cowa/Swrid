#ifndef BUTTON_H
#define BUTTON_H
/**
 * \file Button.H
 * \brief Classe bouton générique pour la gestion de bouton
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

const int NORMAL = 0;
const int HOVER = 1;

 /*! \class Button
   * \brief
   *
   *  La classe de gestion des boutons
   */
class Button
{
    public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Button
     *
     *
     */
        Button(int x,int y);
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe  Button
     *
     *
     */
        virtual ~Button();

    /*!
     *  \brief Accesseur de l'attribut buttonPosition
     *
     *  Méthode qui retourne la SDL_Rec du boutton
     *  \return SDL_Rec ;
     *
     */
        SDL_Rect GetbuttonPosition() { return buttonPosition_; }

     /*!
     *  \brief setteur de l'attribut ButtonPosition
     *
     *  Méthode qui affecte une valeur à l'attribut buttonPosition
     *  \param SDL_Rec : une nouvelle SDL_Rec
     *
     */
        void SetbuttonPosition(SDL_Rect val) { buttonPosition_ = val; }
     /*!
     *  \brief mise en place du bouton sur une surface
     *
     *  Méthode qui permet de mettre en place le bouton sur une surface
     *  \param SDL_surface la surface sur laquelle on "place" l'image
     *
     */
        void applyButton(SDL_Surface* surface);
    /*!
     *  \brief vérification du clique sur le bouton
     *
     *  Méthode qui permet de s'assurer qu'on clique sur le bouton
     *  \param entier mouseX l'abscisse du clique sur l'écran
     *  \param entier mousey l'ordonnée du clique sur l'écran
     *  \return booléen  true si le clique est bien sur le bouton,false sinon
     */

        bool checkClick(int mouseX, int mouseY);
    /*!
     *  \brief changement d'état du bouton
     *
     *  Méthode qui permet de changer l'état du bouton
     *  \param entier correspondant a un état
     *
     *
     */
        void setState(int state);
    /*!
     *  \brief Libération de la mémoire
     *
     *  Méthode qui permet de la mémoire liée aux surfaces utilisées pour le bouton
     *
     */
        void free();

    /*!
     *  \brief Initialisation du bouton
     *
     *  Méthode qui permet d'initialiser  le bouton avec le chemin d'accès
     *  au images correspondante
     *  \param const char* , le chemin d'accès à la première image
     *  \param const char*, le chemin d'accès à la deuxième image
     *
     */
        void init(const char *path1, const char *path2);

    protected:

    private:

    /*!
     *  \brief Attribut d'état du bouton
     *
    */
        int state_;

    /*!
     *  \brief Pointeur sur la  surface du bouton dans l'état normal
     *
    */
        SDL_Surface *bNormal_;
     /*!
     *  \brief Pointeur sur la  surface du bouton dans l'état hover ( enfoncé )
     *
    */
        SDL_Surface *bHover_;
     /*!
     *  \brief Paramètre du bouton ici la position
     *
    */
        SDL_Rect buttonPosition_;
};

#endif // BUTTON_H
