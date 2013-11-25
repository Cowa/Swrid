#ifndef ELEMENTUI_H
#define ELEMENTUI_H
/**
 * \file ElementUI.H
 * \brief  Classe gérant l'affichage graphique des éléments
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

    /*! \class ElementUI
   * \brief
   *
   *  Classe gérant l'affichage graphique des éléments
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
     *  Surcharge du constructeur de la classe ElementUI
     *
     *  \param SDL_Rect, paramètre des éléments
     *  \param entier, x (ligne) de l'élément dans la grille
     *  \param entier, y (colonne) de l'élément dans la grille
     *  \param entier, type de l'éléments
     */

        ElementUI(SDL_Rect form, int x, int y, int type);

     /*!
     *  \brief Méthode de "dessin"
     *
     *  Méthode qui permet de "dessiner" à l'écran l'élément
     *
     *  \param SDL_Surface, la surface sur laquelle on "dessine" l'élément
     *  \param SDL_Surface, la surface image que l'on "colle"
     */
        void draw(SDL_Surface *screen, SDL_Surface *img); // affiche l'élément

    /*!
     *  \brief Méthode de vérification de coordonnée
     *
     *  méthode qui permet vérifier le passage de la souris sur l'élément
     *
     *  \param entier, x l'abscisse de la souris sur l'écran
     *  \param entier, y l'ordonnée de la souris sur l'écran
     *  \return booléen, true si la souris est sur l'élément false sinon
     */

        bool isOn(int x, int y); // vérifie si les coordonnées sont sur lui

    /*!
     *  \brief Méthode de vérification de destination de l'élément
     *
     *  Méthode qui permet de vérifier si l'élément a atteind sa nouvelle "destination"
     *
     *  \return bool
     */
        bool atDestination();

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe  ElementUI
     *
     *
     */


        virtual ~ElementUI();

     /*!
     *  \brief Accesseur de la SDL_Rec de la classe
     *
     *  Méthode qui retourne la SDL_Rec de la classe ElementUI
     *
     *  \return SDl_Rec;
     */
        SDL_Rect getForm();

      /*!
     *  \brief Accesseur de l'abscisse de l'élément sur l'écran
     *
     *  Méthode qui retourne l'abscisse de l'élément sur l'écran
     *
     *  \return entier, x  l'abscisse
     */
        int getX();
    /*!
     *  \brief Accesseur de l'ordonnée de l'élément sur l'écran
     *
     *  Méthode qui retourne l'ordonnée de l'élément sur l'écran
     *
     *  \return entier, y l'ordonnée
     */
        int getY();
    /*!
     *  \brief Accesseur du type de l'élément
     *
     *  Méthode qui retourne l'abscisse de l'élément
     *
     *  \return entier, le type
     */
        int getType();

    /*!
     *  \brief Accesseur de la vélocité x de l'élément sur l'écran
     *
     *  Méthode qui retourne la vélocité x de l'élément sur l'écran
     *
     *  \return entier, la vélocité x
     */

        int getVelX();

    /*!
     *  \brief Accesseur de la vélocité y de l'élément sur l'écran
     *
     *  Méthode qui retourne la vélocité y de l'élément sur l'écran
     *
     *  \return entier, la vélocité y
     */
        int getVelY();

     /*!
     *  \brief Accesseur de la destination x de l'élément sur l'écran
     *
     *  Méthode qui retourne la destination x de l'élément sur l'écran
     *
     *  \return entier, la destination x
     */
        int getDestX();

    /*!
     *  \brief Accesseur de la destination y de l'élément sur l'écran
     *
     *  Méthode qui retourne la destination y de l'élément sur l'écran
     *
     *  \return entier, la destination y
     */
        int getDestY();

     /*!
     *  \brief Setteur de l'abscisse x de l'élément
     *
     *  Méthode qui affecte la nouvelle abscisse à l'élément
     *
     *
     */
        void setX(int x);
     /*!
     *  \brief Setteur de l'ordonnée y de l'élément
     *
     *  Méthode qui affecte la nouvelle ordonnée y de l'élément
     *
     *
     */
        void setY(int y);
     /*!
     *  \brief Setteur du type de l'élément
     *
     *  Méthode qui affecte le nouveau type de l'élément
     *
     *
     */
        void setType(int type);
     /*!
     *  \brief Setteur de SDL_Rec de l'élément
     *
     *  Méthode qui affecte la nouvelle SDL_Rec de l'élément
     *
     *
     */

        void setForm(SDL_Rect form);
        void setFormX(int x);
        void setFormY(int y);

      /*!
     *  \brief Setteur de la vélocité x de l'élément
     *
     *  Méthode qui affecte la vélocité x de l'élément
     *
     *  \param entier
     */
        void setVelX(int x);

      /*!
     *  \brief Setteur de la vélocité y de l'élément
     *
     *  Méthode qui affecte la vélocité y de l'élément
     *
     *  \param entier
     */
        void setVelY(int y);

      /*!
     *  \brief Setteur de la destination x de l'élément sur l'écran
     *
     *  Méthode qui retourne la destination x de l'élément sur l'écran
     *
     *  \param entier
     */
        void setDestX(int x);

      /*!
     *  \brief Setteur de la destination y de l'élément sur l'écran
     *
     *  Méthode qui retourne la destination y de l'élément sur l'écran
     *
     *  \param entier
     */
        void setDestY(int y);

    protected:
    private:
    /*!
     *  \brief Attribut SDL_Rect de l'élément
     *
    */
        SDL_Rect form_; // position (sur l'écran) et forme de l'élément
    /*!
     *  \brief Attribut velx de l'élément
     *
    */
        int velx_; // vitesse sur x
    /*!
     *  \brief Attribut vely de l'élément
     *
    */
        int vely_; // vitesse sur y
    /*!
     *  \brief Attribut destx de l'élément
     *
    */
        int destx_; // destination x
    /*!
     *  \brief Attribut desty de l'élément
     *
    */
        int desty_; // destination y
    /*!
     *  \brief Attribut gridx de l'élément
     *
    */
        int gridx_; // position ligne (sur la grille)
    /*!
     *  \brief Attribut gridy de l'élément
     *
    */
        int gridy_; // position colonne (sur la grille)
    /*!
     *  \brief Attribut type de l'élément
     *
    */
        int type_;
};

#endif // ELEMENTUI_H
