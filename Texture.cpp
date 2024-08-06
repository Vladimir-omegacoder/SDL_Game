#include "Texture.h"

Texture::Texture() : _texture(nullptr), _width(0), _height(0) {}

Texture::~Texture()
{
	Texture::free();
}

void Texture::loadFromFile(SDL_Renderer* renderer, const std::string& path)
{

	free();

	SDL_Texture* finalTexture = nullptr;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		throw;
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 255, 255));
		finalTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		_width = loadedSurface->w;
		_height = loadedSurface->h;

		SDL_FreeSurface(loadedSurface);

		if (finalTexture == nullptr)
		{
			_width = 0;
			_height = 0;
			throw;
		}
	}

	_texture = finalTexture;

}

void Texture::free()
{
	if (_texture != nullptr)
	{
		SDL_DestroyTexture(_texture);
	}
	_width = 0;
	_height = 0;
}

void Texture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip) const
{
	SDL_Rect renderQuad = { x, y, _width, _height };
	if (clip != nullptr)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopy(renderer, _texture, clip, &renderQuad);
}

const SDL_Texture* Texture::getTexture() const
{
	return _texture;
}

size_t Texture::getWidth() const
{
	return _width;
}

size_t Texture::getHeight() const
{
	return _height;
}
