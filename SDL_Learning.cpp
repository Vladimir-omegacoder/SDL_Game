#include <iostream>
#include <string>
#include "SDL.h"



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
SDL_Surface* windowSurface = nullptr;
SDL_Surface* currentSurface = nullptr;
SDL_Surface* keyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];



bool init();

SDL_Surface* loadSurface(const std::string& path);

void close();

bool loadAllMedia();



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

	currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{

				switch (e.key.keysym.sym)
				{

				case SDLK_UP:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_UP];
					break;

				case SDLK_DOWN:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
					break;

				case SDLK_LEFT:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
					break;

				case SDLK_RIGHT:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
					break;

				default:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
					break;
				}

			}
		}

		SDL_BlitSurface(currentSurface, NULL, windowSurface, NULL);
		SDL_UpdateWindowSurface(window);

	}
	
	close();

	return 0;

}



bool init()
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Couldn't initialize SDL. SDL_Error: " << SDL_GetError() << '\n';
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
		std::cerr << "Couldn't create SDL window. SDL_Error: " << SDL_GetError() << '\n';
		return false;
	}
	else
	{
		windowSurface = SDL_GetWindowSurface(window);
	}

	return true;

}

SDL_Surface* loadSurface(const std::string& path)
{
	
	SDL_Surface* surface = SDL_LoadBMP(path.c_str());
	if (surface == nullptr)
	{
		std::cerr << "Unable to load the image \"" << path << "\". SDL_Error: " << SDL_GetError() << '\n';
	}

	return surface;

}

void close()
{

	SDL_FreeSurface(currentSurface);
	currentSurface = nullptr;

	SDL_FreeSurface(windowSurface);
	windowSurface = nullptr;

	SDL_Quit();

}

bool loadAllMedia()
{
	
	keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("defalut_surface.bmp");
	if (keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == nullptr)
	{
		std::cerr << "Unable to load default surface. SDL_Error: " << SDL_GetError() << '\n';
		return false;
	}

	keyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("up_surface.bmp");
	if (keyPressSurfaces[KEY_PRESS_SURFACE_UP] == nullptr)
	{
		std::cerr << "Unable to load up surface. SDL_Error: " << SDL_GetError() << '\n';
		return false;
	}

	keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("down_surface.bmp");
	if (keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == nullptr)
	{
		std::cerr << "Unable to load down surface. SDL_Error: " << SDL_GetError() << '\n';
		return false;
	}

	keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("left_surface.bmp");
	if (keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == nullptr)
	{
		std::cerr << "Unable to load left surface. SDL_Error: " << SDL_GetError() << '\n';
		return false;
	}

	keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("right_surface.bmp");
	if (keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == nullptr)
	{
		std::cerr << "Unable to load right surface. SDL_Error: " << SDL_GetError() << '\n';
		return false;
	}

	return true;

}
