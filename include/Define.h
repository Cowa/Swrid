#ifndef DEFINE_H
#define DEFINE_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_framerate.h>
#include <iostream>
#include <vector>
#include <array>
#include "BaseElement.h"

// Alias utiles
typedef std::vector<std::vector<BaseElement> > Matrix2DElement;
typedef std::vector<std::array<int, 2> > VectorArray2I;

const bool DEBUG = true;
const int FPS = 30;

#endif // DEFINE_H
