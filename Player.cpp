#include "Player.h"

const float Player::MAX_VELOCITY = 500.f;

Player::Player() : _position(0, 0), _velocity(0, 0), _hitbox(), _texture(nullptr) {}

void Player::setHitbox(const SDL_Rect& hitbox)
{
    _hitbox = hitbox;
    _position.x = hitbox.x;
    _position.y = hitbox.y;
}

void Player::setTexture(const Texture* texture)
{
	_texture = texture;
}

void Player::setPosition(const gin::vec2f& position)
{
    _position = position;
    _hitbox.x = position.x;
    _hitbox.y = position.y;
}

SDL_Rect Player::getHitbox() const
{
    return _hitbox;
}

const Texture* Player::getTexture() const
{
	return _texture;
}

gin::vec2f Player::getPosition() const
{
    return _position;
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

void Player::move(uint32_t ticks, SDL_Rect& wall)
{

    gin::vec2f offset = _velocity / static_cast<float>(ticks);

    _position.x += offset.x;
    _hitbox.x = _position.x;

    if (_position.x < 0 || (_position.x + _hitbox.w > WINDOW_WIDTH) || checkCollision(_hitbox, wall))
    {
        _position.x -= offset.x;
        _hitbox.x = _position.x;
    }

    _position.y += offset.y;
    _hitbox.y = _position.y;

    if (_position.y < 0 || (_position.y + _hitbox.h > WINDOW_HEIGHT) || checkCollision(_hitbox, wall))
    {
        _position.y -= offset.y;
        _hitbox.y = _position.y;
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
