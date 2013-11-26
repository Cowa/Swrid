#include "../include/Engine.h"

Engine* Engine::engine_;

Engine::Engine()
{
    grid_ = new Grid();
    grid_->new_row();
    grid_->new_row();
    grid_->new_row();
    grid_->new_row();

    screen_ = new MenuScreen(this);
    menuScreen_ = screen_;
    gameScreen_ = new GameScreen(this);

    player_ = new Player();
}

Engine::Engine(SDL_Surface *sdlScreen, SDL_Event *event, bool *loop)
{
    grid_ = new Grid();

    screen_ = new MenuScreen(Engine::getInstance());
    menuScreen_ = screen_;
    gameScreen_ = new GameScreen(Engine::getInstance());

    player_ = new Player();

    sdlScreen_ = sdlScreen;
    event_ = event;
    loop_ = loop;
}

Engine::~Engine()
{
    if(grid_ != NULL)
        delete grid_;
    if(menuScreen_ != NULL)
        delete menuScreen_;
    if(gameScreen_ != NULL)
        delete gameScreen_;
    if(player_ != NULL)
        delete player_;
}

void Engine::init()
{
    screen_->show(sdlScreen_);
}

void Engine::new_game()
{
    grid_->init();
    grid_->new_row();
    grid_->new_row();
    grid_->new_row();
    grid_->new_row();
}

void Engine::render()
{
    screen_->render(sdlScreen_);
}

void Engine::event()
{
    screen_->event(event_, loop_);
}

/**********
* SETTERS *
**********/
void Engine::setScreen(Screen *screen)
{
    // On libère l'écran actuel
    screen_->hide(sdlScreen_);
    // On change l'écran vers le nouveau
    screen_ = screen;
    // On affiche le nouveau écran
    screen_->show(sdlScreen_);
}

void Engine::setGridMode(GridMode *gridMode)
{
    grid_->setGridMode(gridMode);
}

void Engine::setSDLscreen(SDL_Surface *newScreen)
{
    sdlScreen_ = newScreen;
}

void Engine::setEvent(SDL_Event *event)
{
    event_ = event;
}
void Engine::setLoop(bool *loop)
{
    loop_ = loop;
}

/**********
* GETTERS *
**********/
Grid* Engine::getGrid()
{
    return grid_;
}

Screen* Engine::getScreen()
{
    return screen_;
}

Screen* Engine::getMenuScreen()
{
    return menuScreen_;
}

Screen* Engine::getGameScreen()
{
    return gameScreen_;
}

SDL_Surface* Engine::getSDLscreen()
{
    return sdlScreen_;
}
