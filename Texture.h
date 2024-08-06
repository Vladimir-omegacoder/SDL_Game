#pragma once
#ifndef TEXTURE_CLASS
#define TEXTURE_CLASS

#include "SDL.h"
#include "SDL_image.h"
#include <string>


class Texture
{

private:

	SDL_Texture* _texture;
	size_t _width;
	size_t _height;

public:

	Texture();

	~Texture();

	void loadFromFile(SDL_Renderer* renderer, const std::string& path);

	void free();

	void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = nullptr) const;

	const SDL_Texture* getTexture() const;

	size_t getWidth() const;

	size_t getHeight() const;

	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	void setAlpha(Uint8 alpha);

	void setBlendMode(SDL_BlendMode blending);

};

#endif