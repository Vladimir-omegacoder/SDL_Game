#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "ginner_math.h"

#include "Texture.h"
#include "Timer.h"
#include "Player.h"





enum TexturesKey
{
	TEXTURE_TEXT,
	TEXTURE_TOTAL_COUNT
};

constexpr int WINDOW_WIDTH = 640;
constexpr int WINDOW_HEIGHT = 480;

const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;

SDL_Window* window = nullptr;

SDL_Renderer* renderer = nullptr;


Texture textures[TEXTURE_TOTAL_COUNT] {};

const size_t DATA_SIZE = 10;
Sint32 data[DATA_SIZE];

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

	SDL_Color textColor = { 0, 0, 0, 0xFF };
	SDL_Color highlightColor = { 0xFF, 0, 0, 0xFF };
	
	int currentData = 0;

	SDL_StartTextInput();

	while (quit == false)
	{

		bool renderText = false;

		while (SDL_PollEvent(&e))
		{

			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					textures
					break;

				default:
					break;
				}
			}
			
			
		}

		

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);


		if (renderText)
		{
			if (inputText != "")
			{
				textures[INPUT_TEXTURE].loadFromRenderedText(renderer, inputText, font, textColor);
			}
			else
			{
				textures[INPUT_TEXTURE].loadFromRenderedText(renderer, " ", font, textColor);
			}
		}

		textures[INPUT_TEXTURE].render(renderer,
			(WINDOW_WIDTH - textures[INPUT_TEXTURE].getWidth()) / 2,
			(WINDOW_HEIGHT - textures[INPUT_TEXTURE].getHeight()) / 2);

		SDL_RenderPresent(renderer);

	}

	SDL_StopTextInput();
	
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

	SDL_RWops* file = SDL_RWFromFile("33_file_reading_and_writing/some_stuff.bin", "w+b");
	if (file != nullptr)
	{
		for (size_t i = 0; i < DATA_SIZE; i++)
		{
			SDL_RWwrite(file, &data[i], sizeof(Sint32), 1);
		}

		SDL_RWclose(file);
	}
	else
	{
		std::cerr << "Failed to save the file. SDL Error: " << SDL_GetError() << '\n';
	}

}

bool loadAllMedia()
{

	font = TTF_OpenFont("resources\\calibri.ttf", 28);

	if (!font)
	{
		std::cerr << "Failed to load the font. SDL ttf Error: " << TTF_GetError() << '\n';
		throw;
	}

	SDL_RWops* file = SDL_RWFromFile("resources\\some_stuff.bin", "r+b");
	if (file == nullptr)
	{

		std::cerr << "Failed to open the file. SDL Error: " << SDL_GetError() << '\n';
		file = SDL_RWFromFile("33_file_reading_and_writing/some_stuff.bin", "w+b");

		if (file != nullptr)
		{
			std::cout << "Created new file.\n";
			for (size_t i = 0; i < DATA_SIZE; i++)
			{
				data[i] = 0;
				SDL_RWwrite(file, &data[i], sizeof(Sint32), 1);
			}

			SDL_RWclose(file);
		}
		else
		{
			std::cerr << "Failed to create the file. SDL Error: " << SDL_GetError() << '\n';
			throw;
		}

	}
	else
	{
		std::cout << "Reading file.\n";
		for (size_t i = 0; i < DATA_SIZE; i++)
		{
			SDL_RWread(file, &data[i], sizeof(Sint32), 1);
		}

		SDL_RWclose(file);
	}
	
	std::string text;
	for (size_t i = 0; i < DATA_SIZE; i++)
	{
		text.append(std::to_string(data[i]));
	}

	textures[TEXTURE_TEXT].loadFromRenderedText(renderer, text, font, SDL_Color{ 0, 0, 0, 255 });

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
