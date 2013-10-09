#ifndef ELEMENTUI_H
#define ELEMENTUI_H

#include "Define.h"
#include "Element.h"

/******************************************
* Lien entre la structure Element et l'UI *
******************************************/
class ElementUI
{
    public:
        ElementUI();
        ElementUI(SDL_Rect form, int x, int y, int type);
        void draw(SDL_Surface *grid); // affiche l'élément
        bool isOn(int x, int y); // vérifie si les coordonnées sont sur lui

        virtual ~ElementUI();

        SDL_Rect getForm();
        int getX();
        int getY();
        int getType();
    protected:
    private:
        SDL_Rect form_; // position (sur l'écran) et forme de l'élément
        int gridx_; // position ligne (sur la grille)
        int gridy_; // position colonne (sur la grille)
        int type_;
};

#endif // ELEMENTUI_H
