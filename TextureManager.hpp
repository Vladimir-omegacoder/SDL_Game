#pragma once
#ifndef GAME_TEXURE_MANAGER
#define GAME_TEXURE_MANAGER

#include "SDL_image.h"

class TextureManager
{
public: 
	static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* renderer);
};

#endif