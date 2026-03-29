#include "engine.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <SDL.h>

Engine::Engine(int w, int h, uint8_t delay) {
  this->init(w, h);
  this->running = true;
  this->delay = delay;
}

void Engine::init(int w, int h) {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    throw std::runtime_error(
      std::string("SDL initialization failed: ") + SDL_GetError()
    );
  }

  this->window = std::unique_ptr<SDL_Window, SDL_Window_Deleter>(
    SDL_CreateWindow(
      "Game Engine",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      w,
      h,
      SDL_WINDOW_SHOWN
    )
  );

  if(!window) {
    std::cerr << "Window Creation Failed: " << SDL_GetError() << std::endl;
    this->shutdown();
  }
  this->renderer = std::unique_ptr<SDL_Renderer, SDL_Renderer_Deleter>(
    SDL_CreateRenderer(
      this->window.get(), -1, 0
    )
  );

  if(!renderer) {
    std::cerr << "Renderer Creation Failed: " << SDL_GetError() << std::endl;
    this->shutdown();
  }
}

void Engine::run() {
  while(this->running) {
    SDL_SetRenderDrawColor(
      this->renderer.get(),
      0xFF,
      0xFF,
      0xFF,
      0xFF
    );

    SDL_RenderClear(this->renderer.get());

    SDL_RenderPresent(this->renderer.get());
    SDL_Delay(this->delay);
  }

  this->shutdown();
}

void Engine::shutdown() {
  SDL_Quit();
}
