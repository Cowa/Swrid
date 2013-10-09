#include "../include/MenuScreen.h"
#include "../include/Engine.h"

MenuScreen::MenuScreen(Engine *engine)
{
    engine_ = engine;
}

MenuScreen::~MenuScreen()
{
}

void MenuScreen::show(SDL_Surface *screen)
{
    if(DEBUG)
        std::cout << "On entre dans l'écran Menu" << std::endl;
    resize(screen);
}

void MenuScreen::render(SDL_Surface *screen)
{
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 94, 170, 99)); // On colore le fond
}

void MenuScreen::resize(SDL_Surface *screen)
{
}

void MenuScreen::hide(SDL_Surface *screen)
{
    if(DEBUG)
        std::cout << "On sort de l'écran Menu" << std::endl;
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
                if(event->button.button == SDL_BUTTON_RIGHT)
                    engine_->setScreen(engine_->getGameScreen());
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
