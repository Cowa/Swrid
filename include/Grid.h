#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "Element.h"
#include "GridMode.h"
#include "GridModeNormal.h"
#include "GridModeHard.h"

using namespace std;

class Grid
{
private:
    // The grid (matrix)
    vector<vector<Element> > grid_;
    // Grid mode (normal, hard)
    GridMode *gridMode_;
    // Number of rows
    int n_rows_;
    // Number of columns
    int n_cols_;
    //
    int n_align_;
    // Number of different element's type
    int n_el_;
    // Score
    int score_;
    // Limit reached analysis
    bool limit_reached_;

public:
    Grid(int n_rows=14, int n_cols=12, int n_align=3, int n_el=4);
    ~Grid();

    // Echange deux éléments adjacents, où les tuples contiennent les positions de ces éléments {x, y}
    bool swap(int tuple1[3], int tuple2[3]);

    // Vérifie l'ensemble de la grille pour retirer les couples alignés
    // Utilise les méthodes check_row et check_col
    bool purge();

    // Simule la gravité, on fait tomber vers le bas tout les éléments
    void update_gravity();

    // On pousse toutes les lignes d'un cran vers le haut, et on ajoute une nouvelle ligne d'éléments aléatoire en bas
    void new_row();

    // Vérifie si la limite a été atteinte, et met à jour l'attribut limit_reached_ en conséquences
    void check_limit_reached();

    // Affiche la grille
    string print(vector<vector<Element> > grid);

    // Créer la tranposé d'une matrice d'éléments
    vector<vector<Element> > transpose(vector<vector<Element> > grid);

    /**********
    * GETTERS *
    **********/
    vector<vector<Element> >* getPointerGrid();
    vector<vector<Element> > getGrid();
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
