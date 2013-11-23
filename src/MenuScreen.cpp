#include "../include/MenuScreen.h"
#include "../include/Engine.h"

MenuScreen::MenuScreen(Engine *engine)
{
    engine_ = engine;
    redraw_ = true;

    bg_pos_.x = 0, bg_pos_.y = 0;

    bNormalMode_= new Button(205,280,"img/btnormal.png");
    bHardMode_ = new Button(415,280,"img/btdifficile.png");
    bQuit_ = new Button(650,450,"img/btescape.png");

    /*bNormalMode_->freeButtonSurface();
    bHardMode_->freeButtonSurface();
    bQuit_->freeButtonSurface(); */
}

MenuScreen::~MenuScreen()
{
}

void MenuScreen::show(SDL_Surface *screen)
{
    bg_ = IMG_Load("img/bg_main.jpg");
    bg_opt_ = SDL_DisplayFormat(bg_);
    SDL_FreeSurface(bg_);



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
    bNormalMode_->freeButtonSurface();
    bHardMode_->freeButtonSurface();
    bQuit_->freeButtonSurface();
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

                if(event->button.button == SDL_BUTTON_LEFT && bNormalMode_->checkClick(event->motion.x,event->motion.y)){
                    engine_->setScreen(engine_->getGameScreen());
                }
                break;

            case SDL_MOUSEMOTION :

            if (event->button.button != SDL_BUTTON_LEFT && bNormalMode_->checkClick(event->motion.x,event->motion.y)){

                  bNormalMode_->setPathImg("img/btnormal_hover.png");
                  bNormalMode_->applyButton(engine_->getSDLscreen());
                  redraw_=true;

             }
            else if (event->button.button != SDL_BUTTON_LEFT && !bNormalMode_->checkClick(event->motion.x,event->motion.y)){

                    bNormalMode_->setPathImg("img/btnormal.png");
                    bNormalMode_->applyButton(engine_->getSDLscreen());
                    redraw_=true;
            }

             if (event->button.button != SDL_BUTTON_LEFT && bHardMode_->checkClick(event->motion.x,event->motion.y)){

                bHardMode_->setPathImg("img/btdifficile_hover.png");
                bHardMode_->applyButton(engine_->getSDLscreen());
                redraw_=true;
             }
            else if (event->button.button != SDL_BUTTON_LEFT && !bHardMode_->checkClick(event->motion.x,event->motion.y)){

                    bHardMode_->setPathImg("img/btdifficile.png");
                    bHardMode_->applyButton(engine_->getSDLscreen());
                    redraw_=true;
            }

             if (event->button.button != SDL_BUTTON_LEFT && bQuit_->checkClick(event->motion.x,event->motion.y)){ // the button is hover

                bQuit_->setPathImg("img/btescape_hover.png");
                bQuit_->applyButton(engine_->getSDLscreen());
                redraw_=true;
            }
            else if (event->button.button != SDL_BUTTON_LEFT && !bQuit_->checkClick(event->motion.x,event->motion.y)){ // the button isn't hover

                    bQuit_->setPathImg("img/btescape.png");
                    bQuit_->applyButton(engine_->getSDLscreen());
                    redraw_=true;
            }

            break;
            case SDL_VIDEORESIZE:
                engine_->setSDLscreen(SDL_SetVideoMode(event->resize.w, event->resize.h, 32, SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_RESIZABLE));
                resize(engine_->getSDLscreen());
            default:
                break;
        }
    }
}

void MenuScreen::mouseClick(int x, int y)
{

}
