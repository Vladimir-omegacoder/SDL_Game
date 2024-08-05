#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"



enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};



constexpr int WINDOW_WIDTH = 640;
constexpr int WINDOW_HEIGHT = 480;

SDL_Window* window = nullptr;

SDL_Renderer* renderer = nullptr;

SDL_Texture* texture = nullptr;



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

		SDL_SetRenderDrawColor(renderer, 0, 0, 155, 255);
		SDL_RenderClear(renderer);

		SDL_Rect outline_rect{ WINDOW_WIDTH / 6, WINDOW_HEIGHT / 6, WINDOW_WIDTH * 2 / 3, WINDOW_HEIGHT * 2 / 3 };
		SDL_SetRenderDrawColor(renderer, 155, 0, 255, 255);
		SDL_RenderFillRect(renderer, &outline_rect);

		SDL_Rect rect{ WINDOW_WIDTH / 4, WINDOW_HEIGHT / 4, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
		SDL_SetRenderDrawColor(renderer, 155, 155, 0, 255);
		SDL_RenderDrawRect(renderer, &rect);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderDrawLine(renderer, WINDOW_WIDTH * 0.05, WINDOW_HEIGHT / 2, WINDOW_WIDTH * 0.95, WINDOW_HEIGHT / 2);

		SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
		for (size_t i = 10; i < WINDOW_HEIGHT; i += 10)
		{
			SDL_RenderDrawPoint(renderer, WINDOW_WIDTH / 2, i);
		}

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

	SDL_DestroyTexture(texture);
	texture = nullptr;

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	IMG_Quit();
	SDL_Quit();

}

bool loadAllMedia()
{

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

	/*SDL_Surface* loadedSurface = loadSurface(path);

	if (loadedSurface != nullptr)
	{
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		SDL_FreeSurface(loadedSurface);

		if (newTexture == nullptr)
		{
			std::cerr << "Unable to create texture. SDL Error: " << SDL_GetError() << '\n';
		}
	}*/

	return newTexture;

}
