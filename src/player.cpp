#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Player.hpp"

Player::Player(Vector2f p_pos, SDL_Texture* p_tex)
:Entity(p_pos, p_tex)
{
}

void Player::handleInput(const Uint8* keystate)
{
    if (keystate[SDL_SCANCODE_A])
        pos.x -= 2;

    if (keystate[SDL_SCANCODE_D])
        pos.x += 2;
}

void Player::update(float dt)
{
    velocityY += gravity * dt;
    velocityY = std::min(velocityY, maxFallSpeed);
    pos.y += velocityY * dt;

    if (pos.y > 200)
    {
        pos.y = 0;
    }
}