#include "Player.h"

const float Player::MAX_VELOCITY = 500.f;

Player::Player() : _dimensions(0, 0), _position(0, 0), _velocity(0, 0), _texture(nullptr) {}

void Player::setDimensions(const gin::vec2f& dimensions)
{
	_dimensions = dimensions;
}

void Player::setTexture(const Texture* texture)
{
	_texture = texture;
}

void Player::setPosition(const gin::vec2f& position)
{
    _position = position;
}

gin::vec2f Player::getDimensions() const
{
	return _dimensions;
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

void Player::move(uint32_t ticks)
{

    gin::vec2f _offset = _velocity / static_cast<float>(ticks);

    _position += _offset;

    if (_position.x < 0 || _position.x + _dimensions.x > WINDOW_WIDTH)
    {
        _position.x -= _offset.x;
    }

    if (_position.y < 0 || _position.y + _dimensions.y > WINDOW_HEIGHT)
    {
        _position.y -= _offset.y;
    }

}

void Player::render(SDL_Renderer* renderer) const
{
    _texture->render(renderer, _position.x, _position.y);
}
