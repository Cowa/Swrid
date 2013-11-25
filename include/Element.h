#ifndef ELEMENT_H
#define ELEMENT_H
/**
 * \file Element.H
 * \brief  classe pour géré les éléments de la grille de jeux
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */
#include <cstdlib>

// Type de l'élément neutre
const int NEUTRAL_ELEMENT = 0;
const int VALUE_ELEMENT = 3;
const int MONEY_ELEMENT = 0;

 /*! \class Element
   * \brief
   *
   *  La classe de gestion des éléments
   */

class Element
{
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe element
     *
     *
     */
    Element();

     /*!
     *  \brief Surcharge du constructeur
     *
     *  surcharge du constructeur de la classe Element
     *
     *  \param int type d'élément
     */

    Element(int type);

    /*!
     *  \brief Surcharge du constructeur
     *
     *  surcharge du constructeur de la classe Element
     *
     *  \param booléen random pour la gestion de l'aléatoire
     *  \param entier nombre d'élément
     */

    Element(bool random, int n_el);

     /*!
     *  \brief Destructeur
     *
     *  destructeur de la classe  Element
     *
     *
     */

    ~Element();

     /*!
     *  \brief accesseur de l'attribut value
     *
     *  Methode qui retourne la valeur de l'élément
     *  \return entier, la valeur de l'élément
     *
     */
    int getValue();

    /*!
     *  \brief accesseur de l'attribut Money
     *
     *  Methode qui retourne la money de l'élément
     *  \return entier ;
     *
     */
    int getMoney();

    /*!
     *  \brief accesseur de l'attribut type
     *
     *  Methode qui retourne le type de l'élément
     *  \return entier le type de l'élément ;
     *
     */
    int getType();

    /*!
     *  \brief setteur de l'attribut type
     *
     *  Methode qui affecte un nouveau type à l'élément
     *  \param entier le nouveau type ;
     *
     */
    void setType(int type);

protected:
    /*!
     *  \brief attribut type de l'élément
     *
    */
    int type_;
    /*!
     *  \brief attribut value;
     *
    */
    int value_; //valeur de l'élément (nb de points qu'il va donner lors de sa suppression)
    /*!
     *  \brief attribut money;
     *
    */
    int money_; //argent récupéré lors de sa suppression

};

#endif // ELEMENT_H
