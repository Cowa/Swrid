#ifndef ELEMENT_H
#define ELEMENT_H
/**
 * \file Element.H
 * \brief  Classe pour gérer les éléments de la grille
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
// Valeur des éléments basiques
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
     *  Surcharge du constructeur de la classe Element
     *
     *  \param int type d'élément
     */

    Element(int type);

    /*!
     *  \brief Surcharge du constructeur
     *
     *  Surcharge du constructeur de la classe Element
     *
     *  \param booléen random pour la gestion de l'aléatoire
     *  \param entier nombre de type d'élément
     */

    Element(bool random, int n_el);

     /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe  Element
     *
     *
     */

    ~Element();

     /*!
     *  \brief Accesseur de l'attribut value
     *
     *  Méthode qui retourne la valeur de l'élément
     *  \return entier, la valeur de l'élément
     *
     */
    int getValue();

    /*!
     *  \brief accesseur de l'attribut Money
     *
     *  Méthode qui retourne la money de l'élément
     *  \return entier ;
     *
     */
    int getMoney();

    /*!
     *  \brief Accesseur de l'attribut type
     *
     *  Méthode qui retourne le type de l'élément
     *  \return entier le type de l'élément ;
     *
     */
    int getType();

    /*!
     *  \brief Setteur de l'attribut type
     *
     *  Méthode qui affecte un nouveau type à l'élément
     *  \param entier le nouveau type ;
     *
     */
    void setType(int type);

protected:
    /*!
     *  \brief Attribut type de l'élément
     *
    */
    int type_;
    /*!
     *  \brief Attribut value;
     *
    */
    int value_; //valeur de l'élément (nb de points qu'il va donner lors de sa suppression)
    /*!
     *  \brief Attribut money;
     *
    */
    int money_; //argent récupéré lors de sa suppression

};

#endif // ELEMENT_H
