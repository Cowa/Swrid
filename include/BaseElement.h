#ifndef ELEMENTOPTION_H
#define ELEMENTOPTION_H

/**
 * \file BaseElement.H
 * \brief Décorateur de la classe élément
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */

#include "Element.h"

  /*! \class BaseElement
   * \brief Décorateur de la classe Element
   *
   *  Ajout (ou non) d'un bonus sur les éléments
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
     *  Surcharge du constructeur de la classe  BaseElement
     *
     *  \param Element : L'élément à décorer
     */
        BaseElement(Element el);

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe  BaseElement
     *
     *
     */
        virtual ~BaseElement();

    /*!
     *  \brief Accesseur de l'attribut value
     *
     *  Méthode qui retourne la valeur de l'attribut value
     *  \return entier ;
     *
     */
        int getValue();
    /*!
     *  \brief Accesseur de l'attribut money
     *
     *  Méthode qui retourne la valeur de l'attribut money
     *  \return entier ;
     *
     */
        int getMoney();
    /*!
     *  \brief Accesseur de l'attribut type
     *
     *  Méthode qui retourne la valeur de l'attribut type
     *  \return entier ;
     *
     */
        int getType();

    /*!
     *  \brief setteur de l'attribut value
     *
     *  Méthode qui retourne la valeur de l'attribut value
     *  \return entier ;
     *
     */
        void setType(int type);
    private:
    protected:

    /*!
     *  \brief  L'attribut de type Element
     */

        Element el_;
    /*!
     *  \brief  L'attribut valeur du bonus de type entier
     */
        int bonusValue_;
    /*!
     *  \brief  L'attribut  bonus
     */
        int bonusMoney_;
};

#endif // ELEMENTOPTION_H
