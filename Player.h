#pragma once
#ifndef PLAYER_CLASS
#define PLAYER_CLASS

#include "SDL.h"
#include "ginner_math.h"
#include "Texture.h"
#include <vector>



extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;


struct Circle
{
	gin::vec2f position;
	float radius;
};


class Player
{

private:

	gin::vec2f _position;
	gin::vec2f _velocity;
	SDL_Rect _localBounds;
	Circle _collider;

	const Texture* _texture;

public:

	static const float MAX_VELOCITY;

	Player();

	void setLocalBounds(const SDL_Rect& localBounds);
	void setTexture(const Texture* texture);
	void setPosition(const gin::vec2f& position);
	void setCollider(const Circle& collider);

	SDL_Rect getLocalBounds() const;
	const Texture* getTexture() const;
	gin::vec2f getPosition() const;
	const Circle& getCollider() const;
	Circle& getCollider();

	void handleEvent(SDL_Event& e);

	void move(uint32_t ticks, const std::vector<SDL_Rect>& walls);

	void render(SDL_Renderer* renderer, const gin::vec2f& camera_pos) const;

	static bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);

	static bool checkCollision(const Circle& a, const Circle& b);

	static bool checkCollision(const SDL_Rect& a, const Circle& b);

	static bool checkCollision(const Circle& a, const SDL_Rect& b);

};

#endif