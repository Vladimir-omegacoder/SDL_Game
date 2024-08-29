#pragma once
#ifndef PLAYER_CLASS
#define PLAYER_CLASS

#include "SDL.h"
#include "ginner_math.h"
#include "Texture.h"
#include <vector>



extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

class Player
{

private:

	gin::vec2f _position;
	gin::vec2f _velocity;
	SDL_Rect _localBounds;
	std::vector<SDL_Rect> _colliders;

	const Texture* _texture;

public:

	static const float MAX_VELOCITY;

	Player();

	void setLocalBounds(const SDL_Rect& localBounds);
	void setTexture(const Texture* texture);
	void setPosition(const gin::vec2f& position);
	void setColliders(const std::vector<SDL_Rect>& colliders);

	SDL_Rect getLocalBounds() const;
	const Texture* getTexture() const;
	gin::vec2f getPosition() const;
	const std::vector<SDL_Rect>& getColliders() const;
	std::vector<SDL_Rect>& getColliders();

	void handleEvent(SDL_Event& e);

	void move(uint32_t ticks, const std::vector<SDL_Rect>& walls);

	void render(SDL_Renderer* renderer) const;

	static bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);

};

#endif