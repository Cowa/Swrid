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
}

Grid::~Grid()
{
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
    vector<vector<array<int, 2> > > unloved;
    bool destroyed = false; // booléen pour déterminer si la méthode a détruit ou non des éléments

    for(int i=0; i<n_rows_; i++)
    {
        // On récupère toutes les positions des éléments à retirer des lignes
        unloved.push_back(check_row(grid_, i));
    }

    for(int i=0; i<n_cols_; i++)
    {
        // On récupère toutes les positions des éléments à retirer des lignes
        unloved.push_back(check_col(grid_, i));
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
                grid_[position[0]][position[1]].setType(0);
                score_ += 10; // Prise en compte du score
            }
        }
    }
    return destroyed;
}

vector<array<int, 2> > Grid::check_row(vector<vector<Element> > grid, int i_row)
{
    vector<array<int, 2> > unloved; // liste des positions des éléments à supprimer
    int previous = 0; // type de l'élément précédemment itéré
    int match = 0; // nombre de correspondances successives pour un type d'élément

    for(unsigned int i=0; i<grid[i_row].size(); i++)
    {
        array<int, 2> position;
        position[0] = i_row;

        if(grid[i_row][i].getType() != NEUTRAL_ELEMENT)
        {
            if(match == 0) // Première itération d'un non élément neutre
            {
                position[1] = i;
                previous = grid[i_row][i].getType();
                unloved.push_back(position);
                match = 1;
            }
            else if(grid[i_row][i].getType() != previous)
            {
                if(match < n_align_)
                {
                    for(int j=0; j<match; j++)
                        unloved.pop_back();
                    previous = grid[i_row][i].getType();
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
    if(match != 0 && match < n_align_)
    {
        for(int j=0; j<match; j++)
            unloved.pop_back();
    }

    return unloved;
}

vector<array<int, 2> > Grid::check_col(vector<vector<Element> > grid, int i_col)
{
    // Vérifier une colonne revient à vérifier sa ligne correspondante dans sa transposé
    // On économise une méthode :)
    vector<array<int, 2> > unloved; // liste des positions des éléments à supprimer
    int previous = 0; // type de l'élément précédemment itéré
    int match = 0; // nombre de correspondances successives pour un type d'élément

    grid = transpose(grid);

    for(unsigned int i=0; i<grid[i_col].size(); i++)
    {
        array<int, 2> position;
        position[0] = i;

        if(grid[i_col][i].getType() != NEUTRAL_ELEMENT)
        {
            if(match == 0) // Première itération d'un non élément neutre
            {
                position[1] = i_col;
                previous = grid[i_col][i].getType();
                unloved.push_back(position);
                match = 1;
            }
            else if(grid[i_col][i].getType() != previous)
            {
                if(match < n_align_)
                {
                    for(int j=0; j<match; j++)
                        unloved.pop_back();
                    previous = grid[i_col][i].getType();
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
    if(match != 0 && match < n_align_)
    {
        for(int j=0; j<match; j++)
            unloved.pop_back();
    }

    return unloved;
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
