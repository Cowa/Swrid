#ifndef ELEMENTUI_H
#define ELEMENTUI_H

#include "Define.h"
#include "Element.h"
#include <iostream>

using namespace std;

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
        bool atDestination();

        virtual ~ElementUI();

        SDL_Rect getForm();
        int getX();
        int getY();
        int getType();
        int getVelX();
        int getVelY();
        int getDestX();
        int getDestY();

        void setX(int x);
        void setY(int y);
        void setType(int type);
        void setForm(SDL_Rect form);
        void setFormX(int x);
        void setFormY(int y);
        void setVelX(int x);
        void setVelY(int y);
        void setDestX(int x);
        void setDestY(int y);

    protected:
    private:
        SDL_Rect form_; // position (sur l'écran) et forme de l'élément
        int velx_; // vitesse sur x
        int vely_; // vitesse sur y
        int destx_; // destination x
        int desty_; // destination y
        int gridx_; // position ligne (sur la grille)
        int gridy_; // position colonne (sur la grille)
        int type_;
};

#endif // ELEMENTUI_H
