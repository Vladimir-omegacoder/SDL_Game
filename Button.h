#pragma once
#ifndef BUTTON_CLASS
#define BUTTON_CLASS

#include "SDL.h"
#include "Texture.h"



extern SDL_Rect spriteClips[4];
extern SDL_Renderer* renderer;

extern Texture buttonTexture;

enum ButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};



class Button
{

private:

	SDL_Point _position;
	ButtonSprite _currentSprite;
	const int BUTTON_WIDTH = 300;
	const int BUTTON_HEIGHT = 200;

public:

	Button();

	void setPosition(int x, int y);

	void handleEvent(SDL_Event* e);

	void render();

};

#endif
