#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "Texture.h"



enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

enum TexturesKey
{
	CIRCLES_TEXTURE,
	TEXTURE_TOTAL_COUNT
};

constexpr int WINDOW_WIDTH = 640;
constexpr int WINDOW_HEIGHT = 480;

SDL_Window* window = nullptr;

SDL_Renderer* renderer = nullptr;

Texture textures[TEXTURE_TOTAL_COUNT] {};

SDL_Rect sprites[4];



bool init();

SDL_Surface* loadSurface(const std::string& path);

void close();

bool loadAllMedia();

SDL_Texture* loadTexture(const std::string& path);



int main(int argc, char* args[])
{

	if (!init())
	{
		std::cerr << "Initialization failed.\n";
		return -1;
	}
	
	SDL_Event e;
	bool quit = false;

	if (!loadAllMedia())
	{
		std::cerr << "Unable to load the media.\n";
		return -1;
	}

	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		textures[CIRCLES_TEXTURE].render(renderer, 0, 0, &sprites[0]);
		textures[CIRCLES_TEXTURE].render(renderer, WINDOW_WIDTH - sprites[1].w, 0, &sprites[1]);
		textures[CIRCLES_TEXTURE].render(renderer, 0, WINDOW_HEIGHT - sprites[2].h, &sprites[2]);
		textures[CIRCLES_TEXTURE].render(renderer, WINDOW_WIDTH - sprites[3].w, WINDOW_HEIGHT - sprites[3].h, &sprites[3]);

		SDL_RenderPresent(renderer);

	}
	
	close();

	return 0;

}



bool init()
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Couldn't initialize SDL. SDL Error: " << SDL_GetError() << '\n';
		return false;
	}
	else
	{
		window = SDL_CreateWindow("SDL Learning",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH, WINDOW_HEIGHT,
			SDL_WINDOW_SHOWN);
	}

	if (window == nullptr)
	{
		std::cerr << "Couldn't create SDL window. SDL Error: " << SDL_GetError() << '\n';
		return false;
	}

	int imgFlags = IMG_INIT_PNG;
	if (!((IMG_Init(imgFlags) & imgFlags)))
	{
		std::cerr << "Couldn't initialize SDL_image. SDL image Error: " << IMG_GetError() << '\n';
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		std::cerr << "Couldn't create SDL_renderer. SDL Error: " << SDL_GetError() << '\n';
		return false;
	}
	else
	{
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}

	return true;

}

SDL_Surface* loadSurface(const std::string& path)
{
	
	SDL_Surface* loaded_surface = IMG_Load(path.c_str());

	if (loaded_surface == nullptr)
	{
		std::cerr << "Unable to load the image \"" << path << "\". SDL Error: " << IMG_GetError() << '\n';
	}

	return loaded_surface;

}

void close()
{

	for (size_t i = 0; i < TEXTURE_TOTAL_COUNT; i++)
	{
		textures[i].free();
	}

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

	IMG_Quit();
	SDL_Quit();

}

bool loadAllMedia()
{

	textures[CIRCLES_TEXTURE].loadFromFile(renderer, "resources\\circles.png");

	sprites[0] = SDL_Rect{ 0, 0, 100, 100 };
	sprites[1] = SDL_Rect{ 100, 0, 100, 100 };
	sprites[2] = SDL_Rect{ 0, 100, 100, 100 };
	sprites[3] = SDL_Rect{ 100, 100, 100, 100 };

	return true;

}

SDL_Texture* loadTexture(const std::string& path)
{
	
	SDL_Texture* newTexture = nullptr;

	newTexture = IMG_LoadTexture(renderer, path.c_str());

	if (newTexture == nullptr)
	{
		std::cerr << "Unable to create texture. SDL Error: " << SDL_GetError() << '\n';
	}

	return newTexture;

}
