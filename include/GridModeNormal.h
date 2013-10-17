#ifndef GRIDMODENORMAL_H
#define GRIDMODENORMAL_H

#include "GridMode.h"

using namespace std;

class GridModeNormal: public GridMode
{
    public:
        GridModeNormal();
        virtual ~GridModeNormal();
        bool purge(Grid *grid);

        // Vérifie si l'élément (i, j) est adjacent avec d'autres éléments de même type que lui
        // i, j : position de l'élément
        // crossed : liste des éléments avec les adjacents DEJA analysés
        VectorArray2I adjacentWith(int i, int j, VectorArray2I *crossed, Grid *grid);

        bool isCrossed(int i, int j, VectorArray2I crossed);

    protected:
    private:
};

#endif // GRIDMODENORMAL_H
