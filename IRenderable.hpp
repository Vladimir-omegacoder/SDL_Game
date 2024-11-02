#pragma once
#ifndef GAME_RENDERABLE_CLASS
#define GAME_RENDERABLE_CLASS

#include "SDL_image.h"

class IRenderable
{
public:
	virtual void Render() = 0;
};

#endif