

#ifndef ELEMENTOPTION_H
#define ELEMENTOPTION_H

/**
 * \file BaseElement.H
 * \brief décorateur de la classe élément
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */

#include "Element.h"


  /*! \class BaseElement
   * \brief décorateur de la classe Element
   *
   *  La classe ajout d'un bonus en fonction d'un pourcentage de chance
   */


class BaseElement: public Element
{
    public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe BaseElement
     *
     *
     */
        BaseElement();

    /*!
     *  \brief surchage du constructeur
     *
     *  surcharge du constructeur de la classe  BaseElement
     *
     *  \param Element : l'élément à décoré
     */
        BaseElement(Element el);

    /*!
     *  \brief Destructeur
     *
     *  destructeur de la classe  BaseElement
     *
     *
     */
        virtual ~BaseElement();

    /*!
     *  \brief accesseur de l'attribut value
     *
     *  Methode qui retourne la valeur de l'attribut value
     *  \return entier ;
     *
     */
        int getValue();
    /*!
     *  \brief accesseur de l'attribut money
     *
     *  Methode qui retourne la valeur de l'attribut money
     *  \return entier ;
     *
     */
        int getMoney();
    /*!
     *  \brief accesseur de l'attribut type
     *
     *  Methode qui retourne la valeur de l'attribut type
     *  \return entier ;
     *
     */
        int getType();

    /*!
     *  \brief setteur de l'attribut value
     *
     *  Methode qui retourne la valeur de l'attribut value
     *  \return entier ;
     *
     */
        void setType(int type);
    private:
    protected:

    /*!
     *  \brief  l'attribut de type Element
     */

        Element el_;
    /*!
     *  \brief  l'attribut valeur du bonus  de type entier
     */
        int bonusValue_;
    /*!
     *  \brief  l'attribut  bonus
     */
        int bonusMoney_;
};

#endif // ELEMENTOPTION_H
