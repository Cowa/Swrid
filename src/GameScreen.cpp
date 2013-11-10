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
    animation_push_ = false;
    animation_fall_ = false;

    swapped_ = false;
    purged_ = false;

    bg_pos_.x = 0, bg_pos_.y = 0;

    n_rows_ = engine_->getGrid()->getN_Rows();
    n_cols_ = engine_->getGrid()->getN_Col();

    score_color_ = {255, 255, 255};
}

GameScreen::~GameScreen()
{
}

void GameScreen::show(SDL_Surface *screen)
{
    bg_ = IMG_Load("img/bg_game.jpg");
    SDL_BlitSurface(bg_, NULL, screen, &bg_pos_);

    score_font_ = TTF_OpenFont("font/FreeMono.ttf", 15);

    if(score_font_ == NULL)
    {
        cout << "SDL Font load error" << endl;
        exit(EXIT_FAILURE);
    }
    resize(screen);
}

/*********************************
* Rendu visuel de l'écran de jeu *
*********************************/
void GameScreen::render(SDL_Surface *screen)
{
    if(redraw_)
    {
        /********
        * Score *
        ********/
        score_ = TTF_RenderText_Solid(score_font_, to_string(engine_->getGrid()->getScore()).c_str(), score_color_);

        SDL_BlitSurface(score_, NULL, screen, &score_pos_);

        /*************
        * La grille *
        ************/
        SDL_BlitSurface(bg_, &grid_form_, screen, &grid_form_); 

        /****************
        * Les éléments *
        ***************/
        // Partie costaude...
        // Pas d'animation du swap et du push en cours... on MAJ la grille
        if(!animation_swap_ && !animation_push_ && !animation_fall_)
        {
            redraw_ = false;

            // Si il y a eu un swap ou une suppression
            if(swapped_ || purged_)
            {
                redraw_ = true;

                // on purge tant qu'il y a à supprimer
                purged_ = false;
                if(engine_->getGrid()->purge())
                {
                    purged_ = true;
                    animation_fall_ = true;
                    updateElements();
                    setElementsToBePull();
                    engine_->getGrid()->update_gravity();
                }
                if(!animation_fall_)
                    updateElements();

                // on ajoute la nouvelle ligne, donc on active l'animation du push
                if(swapped_ && !purged_ && !animation_fall_)
                {
                    engine_->getGrid()->new_row();

                    setElementsToBePush(); // on prépare les éléments à être animés

                    animation_push_ = true; // on prévient le programme qu'on va animer

                    swapped_ = false;
                }
            }
            // Si l'animation push et fall a été activée précédemment, on empêche la MAJ des éléments
            if(!animation_push_ && !animation_fall_)
                updateElements();
        }
        // Si l'animation du swap est en cours...
        else if(animation_swap_)
        {
            if(swapping_->atDestination())
            {
                animation_swap_ = false;
                swapping_ = NULL;
                updateElements();
            }
        }
        // Si l'animation du push est en cours...
        else if(animation_push_)
        {
            if(elements_[n_rows_*n_cols_-1].atDestination())
            {
                animation_push_ = false;
                updateElements();
            }
        }
        // Si l'animation du fall est en cours...
        else if(animation_fall_)
        {
            unsigned int i = 0;
            bool ok = true;
            while(i < elements_.size())
            {
                if(!elements_[i].atDestination())
                    ok = false;
                i++;
            }
            if(ok)
            {
                animation_fall_ = false;
                updateElements();
            }
        }
        /***************************
        * On dessine les élements *
        **************************/
        for(unsigned int i=0; i<elements_.size(); i++)
        {
            elements_[i].draw(screen);
            if(select_ != NULL && select_ == &elements_[i])
                boxRGBA(screen, elements_[i].getForm().x, elements_[i].getForm().y, elements_[i].getForm().x+elements_[i].getForm().w, elements_[i].getForm().y+elements_[i].getForm().h, 255, 30, 30, 50);
        }
        SDL_BlitSurface(bg_, &top_grid_, screen, &top_grid_);
        SDL_BlitSurface(bg_, &bottom_grid_, screen, &bottom_grid_);

        /*******************************************
        * Libération des surfaces (de la mémoire) *
        ******************************************/
        SDL_FreeSurface(score_);
    }
}

void GameScreen::resize(SDL_Surface *screen)
{
    redraw_ = true;

    /********
    * Score *
    ********/
    score_pos_.x = 0, score_pos_.y = 0;

    /************
    * La grille *
    ************/
    grid_form_.x = screen->w*0.43, grid_form_.y = screen->h*0.08, grid_form_.h = screen->h*0.80, grid_form_.w = screen->w*0.465;

    col_w_ = (grid_form_.w/n_cols_);
    row_h_ = (grid_form_.h/n_rows_);

    /********************************
    * Zone de clipping de la grille *
    ********************************/
    grid_clipper_ = grid_form_;
    grid_clipper_.y -= row_h_;
    grid_clipper_.h += row_h_*2;

    /*****************************
    * Clipping top & bottom grid *
    *****************************/
    top_grid_.x = grid_form_.x;
    top_grid_.y = grid_form_.y - row_h_;
    top_grid_.h = row_h_;
    top_grid_.w = grid_form_.w;

    bottom_grid_.x = grid_form_.x;
    bottom_grid_.y = grid_form_.y + grid_form_.h;
    bottom_grid_.h = row_h_;
    bottom_grid_.w = grid_form_.w;

    updateElements();
}

void GameScreen::hide(SDL_Surface *screen)
{
    SDL_FreeSurface(bg_);
    TTF_CloseFont(score_font_);
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

    if(!animation_fall_ && !animation_push_ && !animation_swap_)
    {
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
                    current->setVelY(current->getForm().h/8);
                    select_->setVelY(-current->getForm().h/8);
                }
                else
                {
                    current->setVelY(-current->getForm().h/8);
                    select_->setVelY(current->getForm().h/8);
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
                    current->setVelX(current->getForm().w/8);
                    select_->setVelX(-current->getForm().w/8);
                }
                else
                {
                    current->setVelX(-current->getForm().w/8);
                    select_->setVelX(current->getForm().w/8);
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
            form.x = grid_form_.x + col_w_*(j);
            form.y = grid_form_.y + row_h_*(i);
            form.h = row_h_;
            form.w = col_w_;

            ElementUI el(form, i, j, grid_copy[i][j].getType());
            el.setVelX(0);
            el.setVelY(0);

            elements_.push_back(el);
        }
    }
}

void GameScreen::setElementsToBePush()
{
    // On met en place la vitesse et la destination
    for(unsigned int i=0; i<elements_.size(); i++)
    {
        elements_[i].setVelY(-elements_[i].getForm().h/6);
        elements_[i].setDestY(elements_[i].getForm().y - elements_[i].getForm().h - 2);
    }
    // On ajoute la nouvelle ligne (pour l'animer elle aussi)
    for(unsigned int i=0; i<engine_->getGrid()->getGrid()[n_rows_-1].size(); i++)
    {
        SDL_Rect form;
        form.x = grid_form_.x + col_w_*(i);
        form.y = grid_form_.y + row_h_*(n_rows_);
        form.h = row_h_;
        form.w = col_w_;

        ElementUI el(form, n_rows_-1, i, engine_->getGrid()->getGrid()[n_rows_-1][i].getType());
        el.setDestY(row_h_*(n_rows_-1));
        el.setVelY(-elements_[i].getForm().h/6);

        elements_.push_back(el);
    }
}

void GameScreen::setElementsToBePull()
{
    Matrix2DElement cp_grid = engine_->getGrid()->getGrid();
    int tmp = 0;
    if(tmp == 1){}
    // On met en place la vitesse et la destination
    for(int i=elements_.size()-1; i>=0; i--)
    {
        tmp = 0;
        // On ignore la dernière ligne, elle est déjà au sol, et les éléments neutres
        if(elements_[i].getX() < n_rows_-1 && elements_[i].getType() != NEUTRAL_ELEMENT)
        {
            for(int j=1; j<n_rows_-elements_[i].getX(); j++)
            {
                if(cp_grid[elements_[i].getX()+j][elements_[i].getY()].getType() == NEUTRAL_ELEMENT)
                {
                    tmp = j;

                    cp_grid[elements_[i].getX()][elements_[i].getY()].setType(NEUTRAL_ELEMENT);
                    cp_grid[elements_[i].getX()+j][elements_[i].getY()].setType(elements_[i].getType());

                    elements_[i].setVelY(+elements_[i].getForm().h/6);
                    elements_[i].setDestY(elements_[i].getForm().y + (elements_[i].getForm().h)*j + 2);
                }
            }
            for(int j=1; j<tmp; j++)
            {
                cp_grid[elements_[i].getX()+j][elements_[i].getY()].setType(NEUTRAL_ELEMENT);
            }
        }
    }
}