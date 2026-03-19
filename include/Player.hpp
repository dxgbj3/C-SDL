#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <algorithm>

#include "Entity.hpp"

class Player : public Entity
{
public:
    Player(Vector2f p_pos, SDL_Texture* p_tex);

    void handleInput(const Uint8* keystate);
    void update(float dt);

    float maxFallSpeed = 500.0f;
    float velocityY = 0.0f;
    const float gravity = 200.0f;

};
