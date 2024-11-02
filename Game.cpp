#include "Game.hpp"

Game::Game() : _window(nullptr), _renderer(nullptr), _isRunning(false)
{}

Game::~Game()
{}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cerr << "SDL_Init failed: " << SDL_GetError() << '\n';
		return;
	}
	else
	{
		std::cout << "SDL subsystems initialized\n";
	}


	Uint32 flags = 0;
	if (fullscreen)
	{
		flags |= SDL_WINDOW_FULLSCREEN;
	}
	_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

	if (_window == nullptr)
	{
		std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << '\n';
		return;
	}
	else
	{
		std::cout << "Window created\n";
	}


	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (_renderer == nullptr)
	{
		std::cerr << "SDL_CreateRenderer failed: " << SDL_GetError() << '\n';
		return;
	}
	else
	{
		SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
		std::cout << "Renderer created\n";
	}

	_isRunning = true;

}

void Game::HandleEvents()
{

	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		_isRunning = false;
		break;

	default:
		break;
	}

}

void Game::Update()
{

}

void Game::Render()
{
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
}

void Game::Destroy()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
	std::cout << "Game quit\n";
}
