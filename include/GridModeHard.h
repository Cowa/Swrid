#ifndef GRIDMODEHARD_H
#define GRIDMODEHARD_H

#include "GridMode.h"

using namespace std;

class GridModeHard: public GridMode
{
    public:
        GridModeHard();
        virtual ~GridModeHard();
        bool purge(Grid *grid);

        // Vérifie la ligne i_row de la grille, retourne la liste des éléments à retirer
        vector<array<int, 2> > check_row(Grid *grid, int i_row);
        // Vérifie la colonne i_col de la grille, retourne la liste des éléments à retirer
        vector<array<int, 2> > check_col(Grid *grid, int i_col);
    protected:
    private:
};

#endif // GRIDMODEHARD_H
