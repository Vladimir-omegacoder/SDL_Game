#include "Player.h"

const float Player::MAX_VELOCITY = 100.f;

Player::Player() : _position(0, 0), _velocity(0, 0), _localBounds(), _colliders(), _texture(nullptr) {}

void Player::setLocalBounds(const SDL_Rect& localBounds)
{
    _localBounds = localBounds;
}

void Player::setTexture(const Texture* texture)
{
	_texture = texture;
}

void Player::setPosition(const gin::vec2f& position)
{
    _position = position;
}

void Player::setColliders(const std::vector<SDL_Rect>& colliders)
{
    _colliders = colliders;
}

SDL_Rect Player::getLocalBounds() const
{
    return _localBounds;
}

const Texture* Player::getTexture() const
{
	return _texture;
}

gin::vec2f Player::getPosition() const
{
    return _position;
}

const std::vector<SDL_Rect>& Player::getColliders() const
{
    return _colliders;
}

std::vector<SDL_Rect>& Player::getColliders()
{
    return _colliders;
}

void Player::handleEvent(SDL_Event& e)
{

    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        if (e.key.keysym.sym == SDLK_w)
        {
            _velocity.y -= MAX_VELOCITY;
        }
        if (e.key.keysym.sym == SDLK_s)
        {
            _velocity.y += MAX_VELOCITY;
        }
        if (e.key.keysym.sym == SDLK_d)
        {
            _velocity.x += MAX_VELOCITY;
        }
        if (e.key.keysym.sym == SDLK_a)
        {
            _velocity.x -= MAX_VELOCITY;
        }
    }
    if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        if (e.key.keysym.sym == SDLK_w)
        {
            _velocity.y += MAX_VELOCITY;
        }
        if (e.key.keysym.sym == SDLK_s)
        {
            _velocity.y -= MAX_VELOCITY;
        }
        if (e.key.keysym.sym == SDLK_d)
        {
            _velocity.x -= MAX_VELOCITY;
        }
        if (e.key.keysym.sym == SDLK_a)
        {
            _velocity.x += MAX_VELOCITY;
        }
    }

}

void Player::move(uint32_t ticks, const std::vector<SDL_Rect>& walls)
{

    gin::vec2f offset = _velocity / static_cast<float>(ticks);

    SDL_Rect globalBounds;

    _position.x += offset.x;

    globalBounds.x = _position.x + _localBounds.x;
    globalBounds.w = _localBounds.w;
    globalBounds.y = _position.y + _localBounds.y;
    globalBounds.h = _localBounds.h;

    for (auto& i : walls)
    {

        if (checkCollision(globalBounds, i))
        {
            for (auto& j : _colliders)
            {
                SDL_Rect colliderBounds;
                colliderBounds.x = globalBounds.x + j.x;
                colliderBounds.w = j.w;
                colliderBounds.y = globalBounds.y + j.y;
                colliderBounds.h = j.h;
                if (checkCollision(colliderBounds, i))
                {
                    _position.x -= offset.x;
                    break;
                }
            }
            break;
        }

    }

    _position.y += offset.y;

    globalBounds.x = _position.x + _localBounds.x;
    globalBounds.w = _localBounds.w;
    globalBounds.y = _position.y + _localBounds.y;
    globalBounds.h = _localBounds.h;

    for (auto& i : walls)
    {

        for (auto& j : _colliders)
        {
            SDL_Rect colliderBounds;
            colliderBounds.x = globalBounds.x + j.x;
            colliderBounds.w = j.w;
            colliderBounds.y = globalBounds.y + j.y;
            colliderBounds.h = j.h;
            if (checkCollision(colliderBounds, i))
            {
                _position.y -= offset.y;
                break;
            }
        }
        break;

    }

}

void Player::render(SDL_Renderer* renderer) const
{
    _texture->render(renderer, _position.x, _position.y);
}

bool Player::checkCollision(const SDL_Rect& a, const SDL_Rect& b)
{
    if (a.x + a.w < b.x || a.x > b.x + b.w)
    {
        return false;
    }
    if (a.y + a.h < b.y || a.y > b.y + b.h)
    {
        return false;
    }
    return true;
}
