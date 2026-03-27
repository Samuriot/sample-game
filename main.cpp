#include <SDL.h>
#include <iostream>

#include "object.h"

const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;

void close_SDL(SDL_Renderer* renderer, SDL_Window* window); 
void render_obj(SDL_Renderer* renderer, Object* obj);

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow(
        "SDL2 Graphics Test",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    Object player(100, 100, 50, 50);

    while(running) {
      SDL_Event event;
      while (SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
          running = false;
        }
        else if(event.type == SDL_KEYDOWN) {
          switch(event.key.keysym.sym) {
            case SDLK_UP:
              player.decrementY();
              break;
            case SDLK_DOWN:
              player.incrementY();
              break;
            case SDLK_RIGHT:
              player.incrementX();
              break;
            case SDLK_LEFT:
              player.decrementX();
              break;
          }
        }
      }

      //Clear screen
      SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
      SDL_RenderClear( renderer );

      render_obj(renderer, &player);
      SDL_RenderPresent(renderer);
      SDL_Delay(16);  // ~60fps
    }
      close_SDL(renderer, window);
    
    return 0;
}

void close_SDL(SDL_Renderer* renderer, SDL_Window* window) {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void render_obj(SDL_Renderer* renderer, Object* obj) {
  SDL_Rect rect = { obj->getX(), obj->getY(), obj->getWidth(), obj->getHeight() };
  SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
  SDL_RenderFillRect(renderer, &rect);
}
