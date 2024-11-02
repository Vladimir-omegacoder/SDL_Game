#include <iostream>
#include "Game.hpp"



Game* game = nullptr;

int main(int, char**)
{

	const uint32_t FPS = 60;
	const uint32_t frameDelay = 1000 / FPS;

	uint32_t frameStart;
	uint32_t frameTime;

	game = new Game();
	game->Init("GAME", 300, 300, 800, 600, false);

	while (game->IsRunning())
	{

		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();
		
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}

	game->Destroy();

	return 0;

}