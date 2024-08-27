#pragma once
#ifndef PLAYER_CLASS
#define PLAYER_CLASS

#include "SDL.h"
#include "ginner_math.h"
#include "Texture.h"



extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

class Player
{

private:

	gin::vec2f _position;
	gin::vec2f _velocity;
	SDL_Rect _hitbox;

	const Texture* _texture;

public:

	static const float MAX_VELOCITY;

	Player();

	void setHitbox(const SDL_Rect& hitbox);
	void setTexture(const Texture* texture);
	void setPosition(const gin::vec2f& position);

	SDL_Rect getHitbox() const;
	const Texture* getTexture() const;
	gin::vec2f getPosition() const;

	void handleEvent(SDL_Event& e);

	void move(uint32_t ticks, SDL_Rect& wall);

	void render(SDL_Renderer* renderer) const;

	static bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);

};

#endif