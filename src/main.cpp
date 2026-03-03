#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argc, char* args[]) 
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cerr << "IMG_Init Error: " << IMG_GetError() << std::endl;

    RenderWindow window("GAME v1.0", 1280, 720);
    
    SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");


    std::vector<Entity> entities =
    {
        Entity(Vector2f(0, 0), grassTexture),
        Entity(Vector2f(30, 0), grassTexture),
        Entity(Vector2f(30, 30), grassTexture)
    };

    {
        Entity texture1(Vector2f(100, 50), grassTexture);
        
        entities.push_back(texture1);
    }
    bool gameRunning = true;

    SDL_Event event;

    while (gameRunning) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
                gameRunning = false;
        }

        window.clear();
        
        for (Entity& e : entities)
        {
            window.render(e);
        }

        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
