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
    vector<vector<array<int, 2> > > unloved;
    bool destroyed = false; // booléen pour déterminer si la méthode a détruit ou non des éléments

    for(int i=0; i<grid->getN_Rows(); i++)
    {
        // On récupère toutes les positions des éléments à retirer des lignes
        unloved.push_back(check_row(grid, i));
    }

    for(int i=0; i<grid->getN_Col(); i++)
    {
        // On récupère toutes les positions des éléments à retirer des lignes
        unloved.push_back(check_col(grid, i));
    }

    // On supprime tous les éléments à partir de unloved
    for(vector<array<int, 2> > list : unloved)
    {
        // S'il y a des éléments à supprimer
        if(list.size() != 0)
        {
            destroyed = true; // il y a des éléments à supprimer

            for(array<int, 2> & position : list)
            {
                grid->setElementType(position[0], position[1], NEUTRAL_ELEMENT);
                grid->setScore(grid->getScore()+10); // Prise en compte du score
            }
        }
    }
    return destroyed;
}

vector<array<int, 2> > GridModeNormal::check_row(Grid *grid, int i_row)
{
    vector<array<int, 2> > unloved; // liste des positions des éléments à supprimer
    vector<vector<Element> > gridcp = grid->getGrid();

    int previous = 0; // type de l'élément précédemment itéré
    int match = 0; // nombre de correspondances successives pour un type d'élément

    for(unsigned int i=0; i<gridcp[i_row].size(); i++)
    {
        array<int, 2> position;
        position[0] = i_row;

        if(gridcp[i_row][i].getType() != NEUTRAL_ELEMENT)
        {
            if(match == 0) // Première itération d'un non élément neutre
            {
                position[1] = i;
                previous = gridcp[i_row][i].getType();
                unloved.push_back(position);
                match = 1;
            }
            else if(gridcp[i_row][i].getType() != previous)
            {
                if(match < grid->getN_Align())
                {
                    for(int j=0; j<match; j++)
                        unloved.pop_back();
                    previous = gridcp[i_row][i].getType();
                    position[1] = i;
                    unloved.push_back(position);
                    match = 1;
                }
            }
            else
            {
                position[1] = i;
                unloved.push_back(position);
                match++;
            }
        }
    }
    if(match != 0 && match < grid->getN_Align())
    {
        for(int j=0; j<match; j++)
            unloved.pop_back();
    }

    return unloved;
}

vector<array<int, 2> > GridModeNormal::check_col(Grid *grid, int i_col)
{
    vector<vector<Element> > gridy = grid->transpose(grid->getGrid());
    vector<array<int, 2> > unloved; // liste des positions des éléments à supprimer
    int previous = 0; // type de l'élément précédemment itéré
    int match = 0; // nombre de correspondances successives pour un type d'élément

    for(unsigned int i=0; i<gridy[i_col].size(); i++)
    {
        array<int, 2> position;
        position[0] = i;

        if(gridy[i_col][i].getType() != NEUTRAL_ELEMENT)
        {
            if(match == 0) // Première itération d'un non élément neutre
            {
                position[1] = i_col;
                previous = gridy[i_col][i].getType();
                unloved.push_back(position);
                match = 1;
            }
            else if(gridy[i_col][i].getType() != previous)
            {
                if(match < grid->getN_Align())
                {
                    for(int j=0; j<match; j++)
                        unloved.pop_back();
                    previous = gridy[i_col][i].getType();
                    position[1] = i_col;
                    unloved.push_back(position);
                    match = 1;
                }
            }
            else
            {
                position[1] = i_col;
                unloved.push_back(position);
                match++;
            }
        }
    }
    if(match != 0 && match < grid->getN_Align())
    {
        for(int j=0; j<match; j++)
            unloved.pop_back();
    }

    return unloved;
}
