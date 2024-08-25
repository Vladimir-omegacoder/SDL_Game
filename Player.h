#pragma once
#ifndef PLAYER_CLASS
#define PLAYER_CLASS

#include "SDL.h"
#include "ginner_math.h"
#include "Texture.h"
#include <iostream>



extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

class Player
{

private:

	gin::vec2f _dimensions;
	gin::vec2f _position;
	gin::vec2f _velocity;

	const Texture* _texture;

public:

	static const float MAX_VELOCITY;

	Player();

	void setDimensions(const gin::vec2f& dimensions);
	void setTexture(const Texture* texture);
	void setPosition(const gin::vec2f& position);

	gin::vec2f getDimensions() const;
	const Texture* getTexture() const;
	gin::vec2f getPosition() const;

	void handleEvent(SDL_Event& e);

	void move(uint32_t ticks);

	void render(SDL_Renderer* renderer) const;

};

#endif