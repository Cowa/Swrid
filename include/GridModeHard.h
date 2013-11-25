#ifndef GRIDMODEHARD_H
#define GRIDMODEHARD_H

#include "GridMode.h"
/**
 * \file GridModeHard.H
 * \brief  classe GridModeHard
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */
using namespace std;
/*! \class GridModeHard
   * \brief
   *
   *  La classe GridModeHard,
   *  implémente  la GridMode
   *
   */
class GridModeHard: public GridMode
{
    public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe GridModeHard
     *
     */
        GridModeHard();
    /*!
     *  \brief destructeur
     *
     *  destructeur de la classe GridModeHard
     *
     */
        virtual ~GridModeHard();
    /*!
     *  \brief methode purge
     *
     *
     *
     */
        bool purge(Grid *grid);
    /*!
     *  \brief methode check_row
     *
     * méthode qui vérifie la ligne i_row de la grille, retourne la liste des éléments à retirer
     * \param Grid , la grille sur laquelle vérifier la ligne
     * \param Entier, la ligne à vérifier
     * \return VectorArray2I, la liste des éléments à retirer
     */

        VectorArray2I check_row(Grid *grid, int i_row);
    /*!
     *  \brief methode check_col
     *
     * méthode qui vérifie la colonne i_col de la grille, retourne la liste des éléments à retirer
     * \param Grid , la grille sur laquelle vérifier la ligne
     * \param Entier, la colonne à vérifier
     * \return VectorArray2I, la liste des éléments à retirer
     */

        VectorArray2I check_col(Grid *grid, int i_col);
    protected:
    private:
};

#endif // GRIDMODEHARD_H
