#ifndef GRID_H
#define GRID_H
/**
 * \file Grid.H
 * \brief  classe Grid
 * \author Brice Thomas, David Perrai
 * \version 1.0
 * \date 27 novembre 2013
 *
 *
 *
 */
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "Define.h"
#include "BaseElement.h"
#include "PointBonusElement.h"
#include "GridMode.h"
#include "GridModeNormal.h"
#include "GridModeHard.h"

using namespace std;
/*! \class Grid
   * \brief
   *
   *  La classe Grid, classe de gestion de la grille de jeux
   *
   */
class Grid
{
private:

     /*!
     *  \brief attribut grid, une matrice
     *
     */
    // The grid (matrix)
    Matrix2DElement grid_;

     /*!
     *  \brief attribut gridmode_, mode de grille
     *
     */
    // Grid mode (normal, hard)
    GridMode *gridMode_;
     /*!
     *  \brief attribut n_rows, nombre de lignes
     *
     */

    // Number of rows
    int n_rows_;
     /*!
     *  \brief attribut n_cols, nombre de colonnes
     *
     */
    // Number of columns
    int n_cols_;
    //
     /*!
     *  \brief attribut n_align, nombre d'éléments identiques alignés
     *
     */
    int n_align_;
     /*!
     *  \brief attribut n_el_, nombre d'éléments différent
     *
     */
    // Number of different element's type
    int n_el_;
     /*!
     *  \brief attribut score_, score du jeux
     *
     */
    // Score
    int score_;
    /*!
     *  \brief attribut limit_reached, booléen en cas de limite atteinte
     *
     */

    // Limit reached analysis
    bool limit_reached_;

public:

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Grid
     *  \param Entier , nombre de lignes fixé par défaut à 14
     *  \param Entier , nombre de colonnes fixé par défaut à 12
     *  \param Entier , nombre d'éléments à aligner au minimum fixé par défaut à 3
     *  \param Entier , nombre d'éléments distincts
     */
    Grid(int n_rows=14, int n_cols=12, int n_align=3, int n_el=4);

    /*!
     *  \brief desstructeur
     *
     *  desstructeur de la classe Grid
     *
     *
     */
    ~Grid();

      /*!
     *  \brief methode swap
     *
     *  Echange deux éléments adjacents, où les tuples contiennent les positions de ces éléments {x, y}
     *
     *  \param int Tab, tableau de trois éléments
     *  \param int Tab, tableau de deux éléments
     */


    bool swap(int tuple1[3], int tuple2[3]);

    /*!
     *  \brief methode purge
     *
     *  Vérifie l'ensemble de la grille pour retirer les couples alignés
     *  Utilise les méthodes check_row et check_col
     *  \return booléen, true si l'échange s'est déroulé avec succès, false sinon
     */

    bool purge();
     /*!
     *  \brief methode update_gravity
     *
     *  Simule la gravité, on fait tomber vers le bas tous les éléments
     *  \return booléen, true si elle à été réaliser , false sinon
     */
    //
    void update_gravity();

      /*!
     *  \brief methode new_row
     *
     *  On pousse toutes les lignes d'un cran vers le haut (et détecte la fin de partie), et on ajoute une nouvelle ligne en bas de la grille
     *
     */

    void new_row();

    /*!
     *  \brief methode print
     *
     * methode d'affichage de la grille
     *  \param Matrix2DElement, la grille représenté par matrice
     *  \return string, affichage sous forme de string
     */

    // Affiche la grille
    string print(Matrix2DElement grid);

     /*!
     *  \brief methode print
     *
     * methode qui créer la tranposé d'une matrice d'éléments
     *  \param Matrix2DElement, la grille représenté par matrice
     *  \return Matrix2DElement , la grille transposé
     */

    Matrix2DElement transpose(Matrix2DElement grid);

    /**********
    * GETTERS *
    **********/
    Matrix2DElement* getPointerGrid();
    Matrix2DElement getGrid();
    bool getLimitReached();
    int getScore();
    int getN_Rows();
    int getN_Col();
    int getN_El();
    int getN_Align();

    /**********
    * SETTERS *
    **********/
    void setScore(int score);
    void setElementType(int i, int j, int type);
    void setGridMode(GridMode *gridMode);
};

#endif // GRID_H
