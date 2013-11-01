#include "../include/GameScreen.h"
#include "../include/Engine.h"
#include <iostream>
using namespace std;

GameScreen::GameScreen(Engine *engine)
{
    engine_ = engine;

    select_ = NULL;
    swapping_ = NULL;

    redraw_ = true;
    animation_swap_ = false;
    swapped_ = false;

    n_rows_ = engine_->getGrid()->getN_Rows();
    n_cols_ = engine_->getGrid()->getN_Col();
}

GameScreen::~GameScreen()
{
}

void GameScreen::updateElements()
{
    elements_.clear();

    // On récupère une copie de la grille
    Matrix2DElement grid_copy = engine_->getGrid()->getGrid();

    // On parcourt la grille
    for(unsigned int i=0; i<grid_copy.size(); i++)
    {
        for(unsigned int j=0; j<grid_copy[0].size(); j++)
        {
            SDL_Rect form;
            form.x = col_w_*(j)+2+panel_form_.w;
            form.y = row_h_*(i)+2;
            form.h = row_h_-2;
            form.w = col_w_-2;

            ElementUI el(form, i, j, grid_copy[i][j].getType());

            elements_.push_back(el);
        }
    }
}

void GameScreen::show(SDL_Surface *screen)
{
    if(DEBUG)
        std::cout << "On entre dans l'écran Jeu" << std::endl;
    resize(screen);
}

/*********************************
* Rendu visuel de l'écran de jeu *
*********************************/
void GameScreen::render(SDL_Surface *screen)
{
    if(redraw_)
    {
        /***********
        * Le fond *
        **********/
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 150, 70, 30)); // On colore le fond

        /******************
        * Le panel gauche *
        ******************/
        panel_ = SDL_CreateRGBSurface(SDL_HWSURFACE, panel_form_.w, panel_form_.h, 32, 0, 0, 0, 0); // On crée la surface du panel
        SDL_FillRect(panel_, NULL, SDL_MapRGB(screen->format, 0, 0, 0));  // On colore le panel

        SDL_BlitSurface(panel_, NULL, screen, &panel_form_); // on "colle" la surface sur l'écran

        /*************
        * La grille *
        ************/
        // On crée la surface de la grille et on la colorie
        grid_ = SDL_CreateRGBSurface(SDL_HWSURFACE, grid_form_.w, grid_form_.h, 32, 0, 0, 0, 0);
        SDL_FillRect(grid_, NULL, SDL_MapRGB(screen->format, 90, 150, 170));

        // On dessine les lignes
        for(int i=0; i<n_rows_; i++)
        {
            lineRGBA(grid_, 0, row_h_*(i), grid_->w, row_h_*(i),0, 0, 0, 255);
            lineRGBA(grid_, 0, row_h_*(i)+1, grid_->w, row_h_*(i)+1,0, 0, 0, 255);
        }
        // On dessine les colonnes
        for(int i=0; i<n_cols_; i++)
        {
            lineRGBA(grid_, col_w_*(i), 0, col_w_*(i), grid_->h,0, 0, 0, 255);
            lineRGBA(grid_, col_w_*(i)+1, 0, col_w_*(i)+1, grid_->h,0, 0, 0, 255);
        }

        SDL_BlitSurface(grid_, NULL, screen, &grid_form_); // on "colle" la grille sur l'écran

        /****************
        * Les éléments *
        ***************/
        // Pas d'animation du swap en cours... on MAJ la grille
        if(!animation_swap_)
        {
            // Si il y a eu un swap
            if(swapped_)
            {
                // on purge tant qu'il y a à supprimer
                while(engine_->getGrid()->purge())
                {
                    engine_->getGrid()->update_gravity();
                }

                // on ajoute la nouvelle ligne
                engine_->getGrid()->new_row();

                // on purge à nouveau avec la nouvelle ligne, histoire d'être sûr
                while(engine_->getGrid()->purge())
                {
                    engine_->getGrid()->update_gravity();
                }

                swapped_ = false;
            }

            updateElements();
            redraw_ = false;
        }
        // Si l'animation du swap est en cours...
        else
        {
            if((swapping_->getVelX()>0 && swapping_->getForm().x >= swapping_->getDestX()) || (swapping_->getVelX()<0 && swapping_->getForm().x <= swapping_->getDestX()) || (swapping_->getVelY()>0 && swapping_->getForm().y >= swapping_->getDestY()) || (swapping_->getVelY()<0 && swapping_->getForm().y <= swapping_->getDestY()))
            {
                animation_swap_ = false;
                swapping_ = NULL;
                updateElements();
            }
        }

        for(unsigned int i=0; i<elements_.size(); i++)
        {
            elements_[i].draw(screen);
            if(select_ != NULL && select_ == &elements_[i])
                boxRGBA(screen, elements_[i].getForm().x, elements_[i].getForm().y, elements_[i].getForm().x+elements_[i].getForm().w, elements_[i].getForm().y+elements_[i].getForm().h, 255, 30, 30, 50);
        }

        /*******************************************
        * Libération des surfaces (de la mémoire) *
        ******************************************/
        SDL_FreeSurface(panel_);
        SDL_FreeSurface(grid_);
    }
}

void GameScreen::resize(SDL_Surface *screen)
{
    redraw_ = true;

    // On se base en fonction de la résolution de l'écran pour rendre l'interface flexible
    /***********
    * Le panel *
    ***********/
    panel_form_.x = 0, panel_form_.y = 0, panel_form_.h = screen->h, panel_form_.w = screen->w*0.250;

    /************
    * La grille *
    ************/
    grid_form_.x = screen->w*0.250, grid_form_.y = 0, grid_form_.h = screen->h, grid_form_.w = screen->w-(screen->w*0.250);

    col_w_ = (grid_form_.w/n_cols_);
    row_h_ = (grid_form_.h/n_rows_);

    updateElements();
}

void GameScreen::hide(SDL_Surface *screen)
{
    if(DEBUG)
        std::cout << "On sort de l'écran Jeu" << std::endl;
}

void GameScreen::event(SDL_Event *event, bool *loop)
{
    while(SDL_PollEvent(event))
    {
        switch(event->type)
        {
        case SDL_QUIT:
            *loop = false;
            break;
        case SDL_MOUSEBUTTONUP:
            if(event->button.button == SDL_BUTTON_LEFT)
                mouseClick(event->button.x, event->button.y);
            else if(event->button.button == SDL_BUTTON_RIGHT)
                engine_->setScreen(engine_->getMenuScreen());
            break;
        case SDL_VIDEORESIZE:
            engine_->setSDLscreen(SDL_SetVideoMode(event->resize.w, event->resize.h, 32, SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_RESIZABLE));
            resize(engine_->getSDLscreen());
            break;
        default:
            break;
        }
    }
}

void GameScreen::mouseClick(int x, int y)
{
    /***********************************************
    * On gère le cas où l'on clique sur un élément *
    ***********************************************/
    unsigned int i = 0;
    bool found = false;
    ElementUI *current = NULL;

    // Tant qu'on a pas trouvé l'élément correspondant ET qu'on a pas parcourut toute la liste
    while(i<elements_.size() && !found)
    {
        // On vérifie si les coordonnées de la souris correspondent à l'un des éléments
        if(elements_[i].isOn(x, y))
        {
            found = true;
            current = &elements_[i];
            // Si aucun élément n'a été sélectionné auparavant, on met celui ci dans le pointeur
            if(select_ == NULL)
                select_ = &elements_[i];
            // Sinon on tente le swap
            else
            {
                // {x, y, type}
                int el1[3] = {elements_[i].getX(), elements_[i].getY(), elements_[i].getType()};
                int el2[3] = {select_->getX(), select_->getY(), select_->getType()};

                // Swap() renvoit TRUE lorsque l'échange est possible et effectué
                if(engine_->getGrid()->swap(el1, el2))
                {
                    swapped_ = true;
                }
                // Si il n'y a pas eu d'échange et que l'élément sélectionné N'EST PAS celui précédemment sélectionné
                if(!swapped_ && select_ != &elements_[i])
                    select_ = &elements_[i];
                else if(select_ == &elements_[i])
                    select_ = NULL;

            }
        }
        i++;
    }

    // S'il y a eu des éléments échangés, il faut mettre en place l'animation
    if(swapped_)
    {
        animation_swap_ = true;
        // Même x, donc on bouge y
        if(current->getForm().x == select_->getForm().x)
        {
            if(current->getForm().y < select_->getForm().y)
            {
                current->setVelY(current->getForm().h/4);
                select_->setVelY(-current->getForm().h/4);
            }
            else
            {
                current->setVelY(-current->getForm().h/4);
                select_->setVelY(current->getForm().h/4);
            }
            // On met à jour les destinations
            current->setDestY(select_->getForm().y);
            select_->setDestY(current->getForm().y);
        }
        // Sinon, on bouge x
        else
        {
            if(current->getForm().x < select_->getForm().x)
            {
                current->setVelX(current->getForm().w/4);
                select_->setVelX(-current->getForm().w/4);
            }
            else
            {
                current->setVelX(-current->getForm().w/4);
                select_->setVelX(current->getForm().w/4);
            }
            // On met à jour les destinations
            current->setDestX(select_->getForm().x);
            select_->setDestX(current->getForm().x);
        }

        select_ = NULL;
        swapping_ = current;
    }

    redraw_ = true;
}
