#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "Texture.h"





enum TexturesKey
{
	DODIK_TEXTURE,
	TEXTURE_TOTAL_COUNT
};

constexpr int WINDOW_WIDTH = 640;
constexpr int WINDOW_HEIGHT = 480;

SDL_Window* window = nullptr;

SDL_Renderer* renderer = nullptr;


Texture textures[TEXTURE_TOTAL_COUNT] {};

SDL_Rect spriteClips[1];


Mix_Music* music = nullptr;
Mix_Chunk* scratch = nullptr;
Mix_Chunk* high_sound = nullptr;
Mix_Chunk* medium_sound = nullptr;
Mix_Chunk* low_sound = nullptr;


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

	float x = (WINDOW_WIDTH - spriteClips->w) / 2, y = (WINDOW_HEIGHT - spriteClips->h) / 2;

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

				if (e.key.keysym.sym == SDLK_1)
				{
					Mix_PlayChannel(-1, scratch, 0);
				}

				if (e.key.keysym.sym == SDLK_2)
				{
					Mix_PlayChannel(-1, low_sound, 0);
				}

				if (e.key.keysym.sym == SDLK_3)
				{
					Mix_PlayChannel(-1, medium_sound, 0);
				}

				if (e.key.keysym.sym == SDLK_4)
				{
					Mix_PlayChannel(-1, high_sound, 0);
				}

				if (e.key.keysym.sym == SDLK_5)
				{
					if (Mix_PlayingMusic() == 0)
					{
						Mix_PlayMusic(music, 0);
					}
					else
					{
						if (Mix_PausedMusic() == 1)
						{
							Mix_ResumeMusic();
						}
						else
						{
							Mix_PauseMusic();
						}
					}
				}

				if (e.key.keysym.sym == SDLK_0)
				{
					Mix_HaltMusic();
				}

			}
		}

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		textures[DODIK_TEXTURE].render(renderer, x, y, &spriteClips[0]);

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

	Mix_FreeMusic(music);
	music = nullptr;

	Mix_FreeChunk(scratch);
	scratch = nullptr;

	Mix_FreeChunk(low_sound);
	low_sound = nullptr;

	Mix_FreeChunk(medium_sound);
	medium_sound = nullptr;

	Mix_FreeChunk(high_sound);
	high_sound = nullptr;

	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

}

bool loadAllMedia()
{

	textures[DODIK_TEXTURE].loadFromFile(renderer, "resources\\dodik.png");

	spriteClips[0].x = 0;
	spriteClips[0].y = 0;
	spriteClips[0].w = 400;
	spriteClips[0].h = 300;

	music = Mix_LoadMUS("resources\\sick_beat.wav");
	if (music == nullptr)
	{
		std::cerr << "Failed to load beat music. SDL mixer Error: " << Mix_GetError() << '\n';
		throw;
	}

	scratch = Mix_LoadWAV("resources\\very_cool_recording.wav");
	if (scratch == nullptr)
	{
		std::cerr << "Failed to load scratch sound effect. SDL mixer Error: " << Mix_GetError() << '\n';
		throw;
	}

	low_sound = Mix_LoadWAV("resources\\metal_pipe_low.wav");
	if (low_sound == nullptr)
	{
		std::cerr << "Failed to load low sound effect. SDL mixer Error: " << Mix_GetError() << '\n';
		throw;
	}

	medium_sound = Mix_LoadWAV("resources\\metal_pipe_medium.wav");
	if (medium_sound == nullptr)
	{
		std::cerr << "Failed to load medium sound effect. SDL mixer Error: " << Mix_GetError() << '\n';
		throw;
	}

	high_sound = Mix_LoadWAV("resources\\metal_pipe_high.wav");
	if (high_sound == nullptr)
	{
		std::cerr << "Failed to load high sound effect. SDL mixer Error: " << Mix_GetError() << '\n';
		throw;
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
