#ifndef OPTIONVALUE_H
#define OPTIONVALUE_H
/**
 * \file PointBonusElement.H
 * \brief  classe PointBonusElement
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */
#include "BaseElement.h"
/*! \class PointBonusElement
   * \brief
   *
   *  La classe PointBonusElement,
   *  hérite de BaseElement
   *
   */
class PointBonusElement : public BaseElement
{
    public:
     /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe  PointBonusElement
     *  \param Element, l'élément à décoré
     */
        PointBonusElement(Element el);
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe PointBonusElement
     */
        virtual ~PointBonusElement();
     /*!
     *  \brief Accesseur
     *
     *  accesseur de l'attribut valeur de l'élément
     */
        int getValue();
     /*!
     *  \brief Accesseur
     *
     *  accesseur de l'attribut money de l'élément
     */
        int getMoney();
    protected:
};

#endif // OPTIONVALUE_H
