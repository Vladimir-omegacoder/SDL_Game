#include "Button.h"

Texture buttonTexture;

Button::Button() : _position{0, 0}, _currentSprite(BUTTON_SPRITE_MOUSE_OUT)
{}

void Button::setPosition(int x, int y)
{
	_position.x = x;
	_position.y = y;
}

void Button::handleEvent(SDL_Event* e)
{

	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{

		int x, y;
		SDL_GetMouseState(&x, &y);

		bool inside = false;
		if (x > _position.x && x < (_position.x + BUTTON_WIDTH) && y > _position.y && y < (_position.y + BUTTON_HEIGHT))
		{
			inside = true;
		}

		if (!inside)
		{
			_currentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		else
		{
			switch (e->type)
			{

			case SDL_MOUSEMOTION:
				_currentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

			case SDL_MOUSEBUTTONDOWN:
				_currentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;

			case SDL_MOUSEBUTTONUP:
				_currentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;

			}
		}

	}

}

void Button::render()
{
	buttonTexture.render(renderer, _position.x, _position.y, &spriteClips[_currentSprite]);
}

