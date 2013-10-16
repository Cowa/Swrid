#include "../include/Grid.h"

Grid::Grid(int n_rows, int n_cols, int n_align, int n_el)
{
    // Création de la matrice
    grid_.resize(n_rows);
    for (int i = 0 ;i < n_rows; i++)
        grid_[i].resize(n_cols);

    n_rows_        = n_rows;
    n_cols_        = n_cols;
    n_align_       = n_align;
    n_el_          = n_el;
    score_         = 0;
    limit_reached_ = false;

    gridMode_ = new GridModeNormal();
}

Grid::~Grid()
{
    if(gridMode_ != NULL)
        delete gridMode_;
}

bool Grid::swap(int tuple1[3], int tuple2[3])
{
    // Si l'un des deux est l'élément neutre
    if(tuple1[2] == NEUTRAL_ELEMENT || tuple2[2] == NEUTRAL_ELEMENT)
        return false;
    // Même position (= même élément)
    if(tuple1[0] == tuple2[0] && tuple1[1] == tuple2[1])
        return false;
    // Ni dans la même ligne, ni dans la même colonne
    if(tuple1[0] != tuple2[0] and tuple1[1] != tuple2[1])
        return false;
    // Même ligne mais non adjacents
    if(tuple1[0] == tuple2[0] and (tuple1[1]+1 != tuple2[1] and tuple1[1]-1 != tuple2[1]))
        return false;
    // Même colonne mais non adjacents
    if(tuple1[1] == tuple2[1] and (tuple1[0]+1 != tuple2[0] and tuple1[0]-1 != tuple2[0]))
        return false;

    // Maintenant, on est sûr qu'ils sont adjacents, on échange leur place
    Element tmp = grid_[tuple1[0]][tuple1[1]];
    grid_[tuple1[0]][tuple1[1]] = grid_[tuple2[0]][tuple2[1]];
    grid_[tuple2[0]][tuple2[1]] = tmp;

    return true;
}

void Grid::new_row()
{
    // On pousse !
    for(unsigned int i=0; i<grid_.size(); i++)
    {
        for(unsigned int j=0; j<grid_[i].size(); j++)
        {
            if(i != 0)
                grid_[i-1][j] = grid_[i][j];
        }
    }

    // Insertion de la nouvelle ligne
    int tmp_type = 0;
    for(unsigned int i=0; i<grid_[0].size(); i++)
    {
        // On crée un nouvel élément aléatoirement
        Element elt(true, n_el_);

        // On fait en sorte de pas avoir deux éléments de même type côte à côte
        if(tmp_type != 0)
        {
            if(tmp_type == elt.getType())
                elt.setType(((tmp_type+1)%n_el_)+1);
        }

        // On le place dans la grille
        grid_[n_rows_ - 1][i] = elt;

        tmp_type = elt.getType();
    }
}

void Grid::check_limit_reached()
{
    // On parcourt l'ensemble des éléments de la dernière ligne
    for(Element & elt : grid_[0])
    {
        if(elt.getType() != NEUTRAL_ELEMENT)
            limit_reached_ = true;
    }
}

void Grid::update_gravity()
{
    vector<vector<Element> > gridy = transpose(grid_);

    int position = gridy[0].size() - 1;

    for(unsigned int i = 0; i < gridy.size(); i++)
    {
        for(int j = gridy[0].size() - 1; j >= 0; j--)
        {
            if(gridy[i][j].getType() != NEUTRAL_ELEMENT)
            {
                gridy[i][position] = gridy[i][j];
                if(j != position)
                    gridy[i][j] = 0;
                position--;
            }
        }
        position = gridy[0].size() - 1;
    }

    grid_ = transpose(gridy);
}

bool Grid::purge()
{
    return gridMode_->purge(this);
}

string Grid::print(vector<vector<Element> > grid)
{
	string print;

	for(vector<Element> & row : grid)
	{
		print += "|";
		for(Element & elt : row)
		{
			print += " "+ to_string(elt.getType()) +" ";
		}
		print += "|\n";
	}

	return print;
}

vector<vector<Element> > Grid::transpose(vector<vector<Element> > grid)
{
    vector<vector<Element> > transposed;

    /* On crée la forme de la transposé
    Le nombre de ligne est le nombre de colonne de grid,
    et le nombre de colonne est le nombre de ligne de grid */
    transposed.resize(grid[0].size());
    for (unsigned int i = 0 ; i < grid[0].size(); i++)
    {
        transposed[i].resize(grid.size());
    }

    /* On parcourt toutes les lignes et tous les éléments de cette nouvelle matrice
    pour y ajouter les éléments correspondant
    */
    for(unsigned int i = 0; i < transposed.size(); i++)
    {
        for(unsigned int j = 0; j <transposed[0].size(); j++)
        {
            transposed[i][j] = grid[j][i];
        }
    }

    return transposed;
}

/**********
* GETTERS *
**********/
vector<vector<Element> > Grid::getGrid()
{
	return grid_;
}

vector<vector<Element> >* Grid::getPointerGrid()
{
    return &grid_;
}

int Grid::getScore()
{
    return score_;
}
int Grid::getN_Rows()
{
    return n_rows_;
}
int Grid::getN_Col()
{
    return n_cols_;
}
int Grid::getN_El()
{
    return n_el_;
}

int Grid::getN_Align()
{
    return n_align_;
}

/**********
* SETTERS *
**********/
void Grid::setScore(int score)
{
    score_ = score;
}

void Grid::setElementType(int i, int j, int type)
{
   grid_[i][j].setType(type);
}

void Grid::setGridMode(GridMode *gridMode)
{
    if(gridMode_ != NULL)
        delete gridMode_;
    gridMode_ = gridMode;
}
