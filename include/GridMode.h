#ifndef GRIDMODE_H
#define GRIDMODE_H
/**
 * \file GridMode.H
 * \brief  classe GridMode
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */
#include <vector>
#include <array>
#include "Define.h"

class Grid;
class Element;
/*! \class GridMode
   * \brief
   *
   *  Interface GridMode
   *
   *
   */
class GridMode
{
    public:
    /*!
     *  \brief "Constructeur"
     *
     *  "Constructeur" de la classe GridMode
     *
     */
        virtual ~GridMode() {}

    /*!
     *  \brief methode purge
     *
     *  \param Grid , pointeur sur la grille
     *  \return booléen
     */
        virtual bool purge(Grid *grid) = 0;
    protected:
    private:
};

#endif // GRIDMODE_H
