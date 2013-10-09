#ifndef SCREEN_H
#define SCREEN_H

#include "Define.h"

/*******************
* Interface Screen *
*******************/
class Screen
{
    public:
        virtual ~Screen() {}
        virtual void show(SDL_Surface *screen) = 0; // appelée seulement lorsqu'on entre dans l'écran
        virtual void render(SDL_Surface *screen) = 0; // gère l'affichage de l'écran
        virtual void resize(SDL_Surface *screen) = 0; // appelée lors du show() et lorsque la fenêtre et redimensionnée
        virtual void hide(SDL_Surface *screen) = 0; // appelée lorsqu'on quitte l'écran
        virtual void event(SDL_Event *event, bool *loop) = 0; // gère l'ensemble des événements liés à l'écran
        virtual void mouseClick(int x, int y) = 0; // gère l'événement du clic de souris
};

#endif // SCREEN_H
