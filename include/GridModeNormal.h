#ifndef GRIDMODENORMAL_H
#define GRIDMODENORMAL_H
/**
 * \file GridModeNormal.H
 * \brief  classe GridModeHard
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */
#include "GridMode.h"

using namespace std;
/*! \class GridModeNormal
   * \brief
   *
   *  La classe GridModeNormal,
   *  implémente  la GridMode
   *
   */

class GridModeNormal: public GridMode
{
    public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe GridModeNormal
     *
     */
        GridModeNormal();
    /*!
     *  \brief destructeur
     *
     *  destructeur de la classe GridModeNormal
     *
     */
        virtual ~GridModeNormal();
    /*!
     *  \brief methode purge
     *
     */
        bool purge(Grid *grid);
    /*!
     *  \brief methode purge
     *
     *  méthode qui vérifie si l'élément (i, j) est adjacent avec d'autres éléments de même type que lui
     *  \param Entier, position i de l'élément
     *  \param Entier, position j de l'élément
     *  \param VectorArray2I, pointeur vers liste des éléments avec les adjacents DEJA analysés
     *  \param Grid, la grille
     *  \return  VectorArray2I , la liste d'éléments
      */

        VectorArray2I adjacentWith(int i, int j, VectorArray2I *crossed, Grid *grid);

     /*!
     *  \brief methode isCrossed
     *  \param Entier, position i de l'élément
     *
     *  \param VectorArray2I, pointeur vers liste des éléments avec les adjacents DEJA analysés
     */

        bool isCrossed(int i, int j, VectorArray2I crossed);

    protected:
    private:
};

#endif // GRIDMODENORMAL_H
