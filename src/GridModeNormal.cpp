#include "../include/GridModeNormal.h"
#include "../include/GridMode.h"
#include "../include/Grid.h"

GridModeNormal::GridModeNormal()
{
}

GridModeNormal::~GridModeNormal()
{
    //dtor
}

bool GridModeNormal::purge(Grid *grid)
{
    VectorArray2I crossed;
    VectorArray2I unloved;

    array<int, 2> cur_element;
    int match;
    bool destroyed = false;

    for(unsigned int i=0; i<grid->getGrid().size(); i++)
    {
        for(unsigned int j=0; j<grid->getGrid()[0].size(); j++)
        {
            cur_element[0] = i, cur_element[1] = j;
            if(!isCrossed(i, j, crossed) && grid->getGrid()[i][j].getType() != 0)
            {
                // On ajoute l'élément courant dans la liste des suppressions possibles
                match = 1;
                unloved.push_back(cur_element);

                VectorArray2I adjacents = adjacentWith(i, j, &crossed, grid);

                while(adjacents.size() != 0)
                {
                    VectorArray2I cur_adjacents;

                    for(unsigned int k = 0; k < adjacents.size(); k++)
                    {
                        array<int, 2> adjacent_in;
                        adjacent_in[0] = adjacents[k][0], adjacent_in[1] = adjacents[k][1];

                        VectorArray2I adjacents_in = adjacentWith(adjacent_in[0], adjacent_in[1], &crossed, grid);
                        for(unsigned int l = 0; l < adjacents_in.size(); l++)
                        {
                            array<int, 2> adjacent_inin;
                            adjacent_inin[0] = adjacents_in[l][0], adjacent_inin[1] = adjacents_in[l][1];
                            cur_adjacents.push_back(adjacent_inin);
                        }
                        unloved.push_back(adjacent_in);
                        match++;
                    }

                    adjacents = cur_adjacents;
                }
                if(match < grid->getN_Align())
                {
                    for(int k=0; k<match; k++)
                    {
                        unloved.pop_back();
                    }
                }
            }
            match = 0;
        }
    }
    for(array<int, 2> & position : unloved)
    {
        destroyed = true;
        grid->setElementType(position[0], position[1], NEUTRAL_ELEMENT);
        grid->setScore(grid->getScore()+10); // Prise en compte du score
    }

    return destroyed;
}

VectorArray2I GridModeNormal::adjacentWith(int i, int j, VectorArray2I *crossed, Grid *grid)
{
    Matrix2DElement gridcp = grid->getGrid();
    VectorArray2I adjacents;
    int typeToMatch = gridcp[i][j].getType();

    if(!isCrossed(i, j, *crossed))
    {
        // On regarde à gauche et à droite
        if(j-1 >= 0)
        {
            array<int, 2> position;
            position[0] = i, position[1] = j-1;

            if(!isCrossed(i, j-1, *crossed))
            {
                if(gridcp[i][j-1].getType() == typeToMatch)
                    adjacents.push_back(position);
            }
        }
        if(j+1 < grid->getN_Col())
        {
            array<int, 2> position;
            position[0] = i, position[1] = j+1;

            if(!isCrossed(i, j+1, *crossed))
            {
                if(gridcp[i][j+1].getType() == typeToMatch)
                    adjacents.push_back(position);
            }
        }
        // On regarde en haut et en bas
        if(i-1 >= 0)
        {
            array<int, 2> position;
            position[0] = i-1, position[1] = j;

            if(!isCrossed(i-1, j, *crossed))
            {
                if(gridcp[i-1][j].getType() == typeToMatch)
                    adjacents.push_back(position);
            }
        }
        if(i+1 < grid->getN_Rows())
        {
            array<int, 2> position;
            position[0] = i+1, position[1] = j;

            if(!isCrossed(i+1, j, *crossed))
            {
                if(gridcp[i+1][j].getType() == typeToMatch)
                    adjacents.push_back(position);
            }
        }

        // On ajoute l'élément (i,j) dans la liste des traités
        array<int, 2> cur_crossed;
        cur_crossed[0] = i, cur_crossed[1] = j;
        crossed->push_back(cur_crossed);
    }
    return adjacents;
}

bool GridModeNormal::isCrossed(int i, int j, VectorArray2I crossed)
{
    bool found = false;

    for(unsigned int k = 0; k<crossed.size(); k++)
    {
        if(i == crossed[k][0] && j == crossed[k][1])
            found = true;
    }

    return found;
}
