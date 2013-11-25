#include "../include/MenuScreen.h"
#include "../include/Engine.h"

MenuScreen::MenuScreen(Engine *engine)
{
    engine_ = engine;
    redraw_ = true;

    bg_pos_.x = 0, bg_pos_.y = 0;

    bNormalMode_= new Button(205,280);
    bHardMode_ = new Button(415,280);
    bQuit_ = new Button(650,450);
}

MenuScreen::~MenuScreen()
{
}

void MenuScreen::show(SDL_Surface *screen)
{
    bg_ = IMG_Load("img/bg_main.jpg");
    bg_opt_ = SDL_DisplayFormat(bg_);
    SDL_FreeSurface(bg_);

    bNormalMode_->init("img/btnormal.png","img/btnormal_hover.png");
    bHardMode_->init("img/btdifficile.png","img/btdifficile_hover.png");
    bQuit_->init("img/btescape.png","img/btescape_hover.png");

    resize(screen);
}

void MenuScreen::render(SDL_Surface *screen)
{
    if(redraw_)
    {
        redraw_ = false;

        SDL_BlitSurface(bg_opt_ , NULL, screen, &bg_pos_);
        bNormalMode_->applyButton(screen);
        bHardMode_->applyButton(screen);
        bQuit_->applyButton(screen);
    }
}

void MenuScreen::resize(SDL_Surface *screen)
{
    redraw_ = true;
}

void MenuScreen::hide(SDL_Surface *screen)
{
    SDL_FreeSurface(bg_opt_);
    bNormalMode_->free();
    bHardMode_->free();
    bQuit_->free();
}

void MenuScreen::event(SDL_Event *event, bool *loop)
{
    while(SDL_PollEvent(event))
    {
        switch(event->type)
        {
        case SDL_QUIT:
            *loop = false;
            break;


            case SDL_MOUSEBUTTONUP:

                if(event->button.button == SDL_BUTTON_LEFT && bQuit_->checkClick(event->motion.x,event->motion.y)){
                    *loop = false;
                }

                // Clic sur Normal
                else if(event->button.button == SDL_BUTTON_LEFT && bNormalMode_->checkClick(event->button.x,event->button.y))
                {
                    engine_->setScreen(engine_->getGameScreen());
                    engine_->getGrid()->setGridMode(new GridModeNormal());
                    bNormalMode_->setState(NORMAL);
                }
                // Clic sur Difficile
                else if(event->button.button == SDL_BUTTON_LEFT && bHardMode_->checkClick(event->button.x,event->button.y))
                {
                    engine_->setScreen(engine_->getGameScreen());
                    engine_->getGrid()->setGridMode(new GridModeHard());
                    bNormalMode_->setState(NORMAL);
                }

            break;

        case SDL_MOUSEMOTION :
            if(bNormalMode_->checkClick(event->button.x,event->button.y))
            {
                bNormalMode_->setState(HOVER);
                redraw_ = true;

            }
            else if(!bNormalMode_->checkClick(event->button.x,event->button.y))
            {
                bNormalMode_->setState(NORMAL);
                redraw_ = true;
            }
            if(bHardMode_->checkClick(event->button.x,event->button.y))
            {
                bHardMode_->setState(HOVER);
                redraw_ = true;
            }
            else if(!bHardMode_->checkClick(event->button.x,event->button.y))
            {
                bHardMode_->setState(NORMAL);
                redraw_ = true;
            }
            if(bQuit_->checkClick(event->button.x,event->button.y))
            {
                bQuit_->setState(HOVER);
                redraw_ = true;
            }
            else if(!bQuit_->checkClick(event->button.x,event->button.y))
            {
                bQuit_->setState(NORMAL);
                redraw_ = true;
            }
            break;
        default:
            break;
        }
    }
}

void MenuScreen::mouseClick(int x, int y)
{

}
