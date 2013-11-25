#ifndef ELEMENTUI_H
#define ELEMENTUI_H
/**
 * \file ElementUI.H
 * \brief  classe héritant de la classe Element
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */
#include "Define.h"
#include "Element.h"
#include <iostream>

using namespace std;

/******************************************
* Lien entre la structure Element et l'UI *
******************************************/
    /*! \class ElementUI
   * \brief
   *
   *  La classe concrète hériant de Element
   */
class ElementUI
{
    public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe ElementUI
     *
     *
     */
        ElementUI();
      /*!
     *  \brief Surcharge du constructeur
     *
     *  surcharge du constructeur de la classe ElementUI
     *
     *  \param SDL_Rect , paramètre des éléments
     *  \param entier  , x abscisse de l'élément sur l'écran
     *  \param entier , y ordonnée de l'élément sur l'écran
     *  \param entier , type de l'éléments
     */

        ElementUI(SDL_Rect form, int x, int y, int type);

     /*!
     *  \brief methode de "dessin"
     *
     *  méthode qui permet de "dessiné" à l'écran l'élément
     *
     *  \param SDL_Surface, la surface sur laquel on "dessine" l'élément
     *  \param SDL_Surface, la surface image que l'on "colle"
     */
        void draw(SDL_Surface *screen, SDL_Surface *img); // affiche l'élément

    /*!
     *  \brief methode de vérification de coordonnée
     *
     *  méthode qui permet vérifier le passage de la sourie sur l'élément
     *
     *  \param entier, x l'abscisse de la souris sur l'écran
     *  \param entier, y l'ordonnée de la souris sur l'écran
     *  \return booléen, true si la souris est sur l'élément false sinon
     */

        bool isOn(int x, int y); // vérifie si les coordonnées sont sur lui
    /*!
     *  \brief methode de vérification de destination de l'élément
     *
     *  méthode qui permet de vérifier si l'élément a atteind sa nouvelle "destination"
     *
     *  \return bool
     */
        bool atDestination();

    /*!
     *  \brief Destructeur
     *
     *  destructeur de la classe  ElementUI
     *
     *
     */


        virtual ~ElementUI();

     /*!
     *  \brief accesseur de la SDL_Rec de la classe
     *
     *  méthode qui retourne la SDL_Rec de la classe ElementUI
     *
     *  \return SDl_Rec;
     */
        SDL_Rect getForm();

      /*!
     *  \brief accesseur de l'abscisse de l'élément sur l'écran
     *
     *  méthode qui retourne l'abscisse de l'élément sur l'écran
     *
     *  \return entier,x  l'abscisse
     */
        int getX();
    /*!
     *  \brief accesseur de l'ordonnée de l'élément sur l'écran
     *
     *  méthode qui retourne l'ordonnée de l'élément sur l'écran
     *
     *  \return entier, y l'ordonnée
     */
        int getY();
    /*!
     *  \brief accesseur du type de l'élément
     *
     *  méthode qui retourne l'abscisse de l'élément
     *
     *  \return entier, le type
     */
        int getType();

    /*!
     *  \brief accesseur de la vélocité x de l'élément sur l'écran
     *
     *  méthode qui retourne la vélocité x de l'élément sur l'écran
     *
     *  \return entier, la vélocité x
     */

        int getVelX();

    /*!
     *  \brief accesseur de la vélocité y de l'élément sur l'écran
     *
     *  méthode qui retourne la vélocité y de l'élément sur l'écran
     *
     *  \return entier, la vélocité y
     */
        int getVelY();

     /*!
     *  \brief accesseur de la destination x de l'élément sur l'écran
     *
     *  méthode qui retourne la destination x de l'élément sur l'écran
     *
     *  \return entier, la destination x
     */
        int getDestX();

    /*!
     *  \brief accesseur de la destination y de l'élément sur l'écran
     *
     *  méthode qui retourne la destination y de l'élément sur l'écran
     *
     *  \return entier, la destination y
     */
        int getDestY();

     /*!
     *  \brief setteur de l'abscisse x de l'élément
     *
     *  méthode qui affecte la nouvelle abscisse à l'élément
     *
     *
     */
        void setX(int x);
     /*!
     *  \brief setteur de l'ordonnée y de l'élément
     *
     *  méthode qui affecte la nouvelle ordonnée y de l'élément
     *
     *
     */
        void setY(int y);
     /*!
     *  \brief setteur du type de l'élément
     *
     *  méthode qui affecte le nouveau type de l'élément
     *
     *
     */
        void setType(int type);
     /*!
     *  \brief setteur de SDL_Rec de l'élément
     *
     *  méthode qui affecte la nouvelle SDL_Rec de l'élément
     *
     *
     */
        void setForm(SDL_Rect form);


        void setFormX(int x);

        void setFormY(int y);
      /*!
     *  \brief setteur de la vélocité x de l'élément
     *
     *  méthode qui affecte la vélocité x de l'élément
     *
     *  \param entier
     */
        void setVelX(int x);
      /*!
     *  \brief setteur de la vélocité y de l'élément
     *
     *  méthode qui affecte la vélocité y de l'élément
     *
     *  \param entier
     */
        void setVelY(int y);
      /*!
     *  \brief setteur de la destination x de l'élément sur l'écran
     *
     *  méthode qui retourne la destination x de l'élément sur l'écran
     *
     *  \param entier
     */
        void setDestX(int x);
      /*!
     *  \brief setteur de la destination y de l'élément sur l'écran
     *
     *  méthode qui retourne la destination y de l'élément sur l'écran
     *
     *  \param entier
     */
        void setDestY(int y);

    protected:
    private:
    /*!
     *  \brief attribut SDL_Rect de l'élément
     *
    */
        SDL_Rect form_; // position (sur l'écran) et forme de l'élément
    /*!
     *  \brief attribut velx de l'élément
     *
    */
        int velx_; // vitesse sur x
    /*!
     *  \brief attribut vely de l'élément
     *
    */
        int vely_; // vitesse sur y
    /*!
     *  \brief attribut destx de l'élément
     *
    */
        int destx_; // destination x
    /*!
     *  \brief attribut desty de l'élément
     *
    */
        int desty_; // destination y
    /*!
     *  \brief attribut gridx de l'élément
     *
    */
        int gridx_; // position ligne (sur la grille)
    /*!
     *  \brief attribut gridy de l'élément
     *
    */
        int gridy_; // position colonne (sur la grille)
    /*!
     *  \brief attribut type de l'élément
     *
    */
        int type_;
};

#endif // ELEMENTUI_H
