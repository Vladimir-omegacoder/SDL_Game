#include <iostream>
#include <string>
#include <exception>
#include <sstream>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#include "Texture.h"
#include "Timer.h"





enum TexturesKey
{
	TEXT_TEXTURE_TIME_ELAPSED,
	TEXT_TEXTURE_TIME_RESTART,
	TEXT_TEXTURE_TIME_PAUSE,
	TEXTURE_TOTAL_COUNT
};

constexpr int WINDOW_WIDTH = 640;
constexpr int WINDOW_HEIGHT = 480;

SDL_Window* window = nullptr;

SDL_Renderer* renderer = nullptr;


Texture textures[TEXTURE_TOTAL_COUNT] {};

SDL_Rect spriteClips[1];


TTF_Font* font = nullptr;


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

	Timer timer;

	std::stringstream timeText;

	float x, y;

	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			if (e.type == SDL_KEYDOWN)
			{

				if (e.key.keysym.sym == SDLK_RETURN)
				{
					if (timer.isStarted())
					{
						timer.stop();
					}
					else
					{
						timer.start();
					}
				}

				if (e.key.keysym.sym == SDLK_SPACE)
				{
					if (timer.isPaused())
					{
						timer.unpause();
					}
					else
					{
						timer.pause();
					}
				}

			}
		}

		timeText.str("");
		timeText << "You wasted " << timer.getTicks() / 1000.f << " s of your life";
		textures[TEXT_TEXTURE_TIME_ELAPSED].loadFromRenderedText(
			renderer, timeText.str().c_str(), font, SDL_Color{ 0, 0, 0, 255 });

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		x = (WINDOW_WIDTH - textures[TEXT_TEXTURE_TIME_RESTART].getWidth()) / 2;
		y = 100;
		textures[TEXT_TEXTURE_TIME_RESTART].render(renderer, x, y);

		x = (WINDOW_WIDTH - textures[TEXT_TEXTURE_TIME_PAUSE].getWidth()) / 2;
		y = 130;
		textures[TEXT_TEXTURE_TIME_PAUSE].render(renderer, x, y);

		x = (WINDOW_WIDTH - textures[TEXT_TEXTURE_TIME_ELAPSED].getWidth()) / 2;
		y = (WINDOW_HEIGHT - textures[TEXT_TEXTURE_TIME_ELAPSED].getHeight()) / 2;
		textures[TEXT_TEXTURE_TIME_ELAPSED].render(renderer, x, y);

		SDL_RenderPresent(renderer);

	}
	
	close();

	return 0;

}



bool init()
{

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
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

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cerr << "Couldn't initialize SDL_mixer. SDL mixer Error: " << Mix_GetError() << '\n';
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

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

	TTF_CloseFont(font);
	font = nullptr;

	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

}

bool loadAllMedia()
{

	font = TTF_OpenFont("resources\\calibri.ttf", 28);

	if (!font)
	{
		std::cerr << "Failed to load the font. SDL ttf Error: " << TTF_GetError() << '\n';
		throw;
	}

	try
	{
		textures[TEXT_TEXTURE_TIME_RESTART].loadFromRenderedText(
			renderer, "Press Enter to start/stop wasting your time", font, SDL_Color{ 0, 0, 0, 255 });
		textures[TEXT_TEXTURE_TIME_PAUSE].loadFromRenderedText(
			renderer, "Press Space to pause/unpause time wasting", font, SDL_Color{ 0, 0, 0, 255 });
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Failed to load the texture.\n";
	}

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
