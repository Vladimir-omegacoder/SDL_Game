#include "Player.h"

const float Player::MAX_VELOCITY = 100.f;

Player::Player() : _position(0, 0), _velocity(0, 0), _localBounds(), _collider(), _texture(nullptr) {}

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

void Player::setCollider(const Circle& collider)
{
    _collider = collider;
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

const Circle& Player::getCollider() const
{
    return _collider;
}

Circle& Player::getCollider()
{
    return _collider;
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
    Circle colliderGlobalBounds;

    _position.x += offset.x;

    globalBounds.x = _position.x + _localBounds.x;
    globalBounds.w = _localBounds.w;
    globalBounds.y = _position.y + _localBounds.y;
    globalBounds.h = _localBounds.h;

    colliderGlobalBounds.position.x = globalBounds.x + _collider.position.x;
    colliderGlobalBounds.position.y = globalBounds.y + _collider.position.y;
    colliderGlobalBounds.radius = _collider.radius;

    for (auto& i : walls)
    {
        if (checkCollision(colliderGlobalBounds, i))
        {
            _position.x -= offset.x;
            break;
        }
    }

    _position.y += offset.y;

    globalBounds.x = _position.x + _localBounds.x;
    globalBounds.w = _localBounds.w;
    globalBounds.y = _position.y + _localBounds.y;
    globalBounds.h = _localBounds.h;

    colliderGlobalBounds.position.x = globalBounds.x + _collider.position.x;
    colliderGlobalBounds.position.y = globalBounds.y + _collider.position.y;
    colliderGlobalBounds.radius = _collider.radius;

    for (auto& i : walls)
    {
        if (checkCollision(colliderGlobalBounds, i))
        {
            _position.y -= offset.y;
            break;
        }
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

bool Player::checkCollision(const Circle& a, const Circle& b)
{
    return gin::distance(a.position, b.position) < (a.radius + b.radius);
}

bool Player::checkCollision(const SDL_Rect& a, const Circle& b)
{
    
    gin::vec2f closest_point;
    if (b.position.x < a.x)
    {
        closest_point.x = a.x;
    }
    else if (b.position.x > a.x + a.w)
    {
        closest_point.x = a.x + a.w;
    }
    else
    {
        closest_point.x = b.position.x;
    }

    if (b.position.y < a.y)
    {
        closest_point.y = a.y;
    }
    else if (b.position.y > a.y + a.h)
    {
        closest_point.y = a.y + a.h;
    }
    else
    {
        closest_point.y = b.position.y;
    }

    return gin::distance(closest_point, b.position) < b.radius;

}

bool Player::checkCollision(const Circle& a, const SDL_Rect& b)
{
    return checkCollision(b, a);
}
