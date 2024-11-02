#pragma once
#ifndef GAME_SPRITE_CLASS
#define GAME_SPRITE_CLASS

#include "Assertions.hpp"
#include "IRenderable.hpp"
#include "TextureManager.hpp"

class Sprite : public IRenderable
{

private:

	SDL_Texture* _texture;
	SDL_Rect _sourceRect;
	SDL_Rect _destinationRect;
	SDL_Renderer* _renderer;

public:

	Sprite();
	Sprite(SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect destinationRect, SDL_Renderer* renderer);

	inline void SetTexture(SDL_Texture* texture) { _texture = texture; }
	inline void SetSourceRect(SDL_Rect sourceRect) { _sourceRect = sourceRect; }
	inline void SetDestinationRect(SDL_Rect destinationRect) { _destinationRect = destinationRect; }
	inline void SetRenderer(SDL_Renderer* renderer) { _renderer = renderer; }

	inline SDL_Texture* GetTexture() { return _texture; }
	inline SDL_Rect GetSourceRect() const { return _sourceRect; }
	inline SDL_Rect GetDestinationRect() const { return _destinationRect; }
	inline SDL_Renderer* GetRenderer() { return _renderer; }

	virtual void Render() override;

};

#endif