#include "engine.h"

#include <stdexcept>
#include <SDL.h>

Engine::Engine(int w, int h) {
  this->init(int w, int h);
}

void Engine::init(int w, int h) {
  if(SDL_Init(SDL_INIT_VIDEO < 0)) {
    throw std::runtime_error("SDL initialization failed: " + SDL_GetError());
  }

  this->window = SDL_CreateWindow(
    "Game Engine",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    w,
    h,
    SDL_WINDOW_SHOWN
  );

  if(!window) {
    
  }
}
