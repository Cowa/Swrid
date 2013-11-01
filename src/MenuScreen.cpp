#include "../include/MenuScreen.h"
#include "../include/Engine.h"

MenuScreen::MenuScreen(Engine *engine)
{
    engine_ = engine;
    redraw_ = true;

    title_color_ = {255, 255, 255};
}

MenuScreen::~MenuScreen()
{
}

void MenuScreen::show(SDL_Surface *screen)
{
    if(DEBUG)
        std::cout << "On entre dans l'écran Menu" << std::endl;

    title_font_ = TTF_OpenFont("font/mt.ttf", 20);

    if(title_font_ == NULL)
    {
        cout << "SDL Font load error" << endl;
        exit(EXIT_FAILURE);
    }
    resize(screen);
}

void MenuScreen::render(SDL_Surface *screen)
{
    if(redraw_)
    {
        string title = "Swrid game prototype";
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 90, 150, 170)); // On colore le fond

        title_ = TTF_RenderText_Solid(title_font_, title.c_str(), title_color_);

        redraw_ = false;

        SDL_BlitSurface(title_, NULL, screen, &title_pos_);
        SDL_FreeSurface(title_);
    }
}

void MenuScreen::resize(SDL_Surface *screen)
{
    redraw_ = true;

    title_pos_.x = screen->w/3;
    title_pos_.y = 10;
}

void MenuScreen::hide(SDL_Surface *screen)
{
    if(DEBUG)
        std::cout << "On sort de l'écran Menu" << std::endl;
    TTF_CloseFont(title_font_);
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
