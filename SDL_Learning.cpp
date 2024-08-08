#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Texture.h"
#include "Button.h"





enum TexturesKey
{
	BUTTON_TEXTURE,
	TEXTURE_TOTAL_COUNT
};

constexpr int WINDOW_WIDTH = 640;
constexpr int WINDOW_HEIGHT = 480;

SDL_Window* window = nullptr;

SDL_Renderer* renderer = nullptr;

Texture textures[TEXTURE_TOTAL_COUNT] {};

TTF_Font* font = nullptr;

SDL_Rect spriteClips[4];

Button buttons[4];


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

	buttons[0].setPosition(0, 0);
	buttons[1].setPosition(300, 0);
	buttons[2].setPosition(0, 200);
	buttons[3].setPosition(300, 200);

	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			for (size_t i = 0; i < 4; i++)
			{
				buttons[i].handleEvent(&e);
			}
		}

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		for (size_t i = 0; i < 4; i++)
		{
			buttons[i].render();
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

	if (TTF_Init() == -1)
	{
		std::cerr << "Couldn't initialize SDL_ttf. SDL ttf Error: " << TTF_GetError() << '\n';
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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

	TTF_CloseFont(font);
	font = nullptr;

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

}

bool loadAllMedia()
{

	textures[BUTTON_TEXTURE].loadFromFile(renderer, "resources\\button.png");

	spriteClips[0].x = 0;
	spriteClips[0].y = 0;
	spriteClips[0].w = 300;
	spriteClips[0].h = 200;

	spriteClips[1].x = 300;
	spriteClips[1].y = 0;
	spriteClips[1].w = 300;
	spriteClips[1].h = 200;

	spriteClips[2].x = 0;
	spriteClips[2].y = 200;
	spriteClips[2].w = 300;
	spriteClips[2].h = 200;

	spriteClips[3].x = 300;
	spriteClips[3].y = 200;
	spriteClips[3].w = 300;
	spriteClips[3].h = 200;

	buttonTexture = textures[BUTTON_TEXTURE];

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
