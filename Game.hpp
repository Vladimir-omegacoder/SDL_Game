#pragma once
#ifndef GAME_CLASS
#define GAME_CLASS

#include <iostream>
#include <string>
#include "SDL.h"



class Game
{

private:

	SDL_Window* _window;
	SDL_Renderer* _renderer;
	bool _isRunning;

public:

	Game();
	~Game();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void Destroy();

	inline bool IsRunning() const;

};



inline bool Game::IsRunning() const
{
	return _isRunning;
}



#endif