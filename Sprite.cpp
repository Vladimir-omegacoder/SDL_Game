#include "Sprite.hpp"

Sprite::Sprite() : _texture(nullptr), _sourceRect(), _destinationRect(), _renderer(nullptr)
{}

Sprite::Sprite(SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect destinationRect, SDL_Renderer* renderer) :
	_texture(texture), _sourceRect(sourceRect), _destinationRect(destinationRect), _renderer(renderer)
{}

void Sprite::Render()
{
	int res = SDL_RenderCopy(_renderer, _texture, &_sourceRect, &_destinationRect);
	GAME_ASSERT((res == 0 && "Sprite rendering error: ") || SDL_GetError());
}
