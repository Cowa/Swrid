#include "../include/GameScreen.h"
#include "../include/Engine.h"

GameScreen::GameScreen(Engine *engine)
{
    engine_ = engine;

    select_ = NULL;

    redraw_ = true;
}

GameScreen::~GameScreen()
{
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
         /***********************************
        * On récupère les variables utiles *
        ***********************************/
        int n_rows = engine_->getGrid()->getN_Rows();
        int n_cols = engine_->getGrid()->getN_Col();

        int col_w = (grid_form_.w/n_cols); // la largeur des colonnes en fonction du nombre de colonnes et de la taille de la grille
        int row_h = (grid_form_.h/n_rows); // la hauteur des lignes en fonction du nombre de lignes et de la taille de la grille

         /**********
        * Le fond *
        **********/
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 150, 70, 30)); // On colore le fond

         /******************
        * Le panel gauche *
        ******************/
        panel_ = SDL_CreateRGBSurface(SDL_HWSURFACE, panel_form_.w, panel_form_.h, 32, 0, 0, 0, 0); // On crée la surface du panel
        SDL_FillRect(panel_, NULL, SDL_MapRGB(screen->format, 0, 0, 0));  // On colore le panel

        SDL_BlitSurface(panel_, NULL, screen, &panel_form_); // on "colle" la surface sur l'écran

         /************
        * La grille *
        ************/
        // On vide la liste des éléments
        elements_.clear();

        // On crée la surface de la grille et on la colorie
        grid_ = SDL_CreateRGBSurface(SDL_HWSURFACE, grid_form_.w, grid_form_.h, 32, 0, 0, 0, 0);
        SDL_FillRect(grid_, NULL, SDL_MapRGB(screen->format, 90, 150, 170));

        // On dessine les lignes
        for(int i=0; i<n_rows; i++)
        {
            lineRGBA(grid_, 0, row_h*(i), grid_->w, row_h*(i),0, 0, 0, 255);
            lineRGBA(grid_, 0, row_h*(i)+1, grid_->w, row_h*(i)+1,0, 0, 0, 255);
        }
        // On dessine les colonnes
        for(int i=0; i<n_cols; i++)
        {
            lineRGBA(grid_, col_w*(i), 0, col_w*(i), grid_->h,0, 0, 0, 255);
            lineRGBA(grid_, col_w*(i)+1, 0, col_w*(i)+1, grid_->h,0, 0, 0, 255);
        }

        // On récupère une copie de la grille
        Matrix2DElement grid_copy = engine_->getGrid()->getGrid();

        // On parcourt la grille
        for(unsigned int i=0; i<grid_copy.size(); i++)
        {
            for(unsigned int j=0; j<grid_copy[0].size(); j++)
            {
                // On remplit la liste des éléments
                SDL_Rect el_form;
                el_form.x = col_w*(j)+2+panel_form_.w, el_form.y = row_h*(i)+2, el_form.h = row_h-2, el_form.w = col_w-2;
                ElementUI el(el_form, i, j, grid_copy[i][j].getType());

                elements_.push_back(el);
            }
        }
        SDL_BlitSurface(grid_, NULL, screen, &grid_form_); // on "colle" la grille sur l'écran

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

        redraw_ = false;
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
    bool found = false, swapped = false;

    // Tant qu'on a pas trouvé l'élément correspondant ET qu'on a pas parcourut toute la liste
    while(i<elements_.size() && !found)
    {
            // On vérifie si les coordonnées de la souris correspondent à l'un des éléments
            if(elements_[i].isOn(x, y))
            {
                found = true;
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
                        swapped = true;
                    }
                    // Si il n'y a pas eu d'échange et que l'élément sélectionné N'EST PAS celui précédemment sélectionné
                    if(!swapped && select_ != &elements_[i])
                        select_ = &elements_[i];
                    else
                        select_ = NULL; // on remet à zéro le pointeur
                }
            }
            i++;
    }

    // S'il y a eu des éléments échangés, il faut mettre à jour la grille
    if(swapped)
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
    }

    redraw_ = true;
}
