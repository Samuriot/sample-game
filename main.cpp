#include <SDL.h>
#include <iostream>

#include "object.h"

const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;
const int GRAVITY = 1;
const int MOVE_SPEED = 5;
const int JUMP_FORCE = -15;

// updates the player object based on key press
void update_obj(Object* obj, int velX);

// object rendering layer using SDL
void render_obj(SDL_Renderer* renderer, Object* obj);

// main event loop that polls for key presses
bool event_loop(Object* obj);

// graceful exit of SDL
void close_SDL(SDL_Renderer* renderer, SDL_Window* window); 


int main() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
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
    if(!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    Object player(100, 100, 50, 50);

    while(running) {
      running = event_loop(&player);

      //Clear screen
      SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
      SDL_RenderClear(renderer);

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
  SDL_Rect rect = {obj->getX(), obj->getY(), obj->getWidth(), obj->getHeight()};
  SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
  SDL_RenderFillRect(renderer, &rect);
}

bool event_loop(Object* player) {
  // event loop for keypress + escape
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    if(event.type == SDL_QUIT) {
      return false;
    }
    else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
      // Only jump if on the ground
      if(player->getY() + player->getHeight() >= SCREEN_HEIGHT) {
        player->setVelY(JUMP_FORCE);
      }
    }
  }      
  // Check held keys
  const Uint8* keys = SDL_GetKeyboardState(NULL);
  int velX = 0;
  if(keys[SDL_SCANCODE_LEFT])  
    velX -= MOVE_SPEED;
  if(keys[SDL_SCANCODE_RIGHT]) 
    velX += MOVE_SPEED;
  update_obj(player, velX);
  return true;
}

void update_obj(Object* player, int velX) {
  // Update player velocity
  player->setVelX(velX);

  // Apply gravity
  player->setVelY(player->getVelY() + GRAVITY);

  // Apply velocity to position
  player->applyVelocity();

  // Collision Physics
  if(player->getY() + player->getHeight() > SCREEN_HEIGHT) {
    player->setY(SCREEN_HEIGHT - player->getHeight());
    player->setVelY(0);
  }
  // right side collision 
  if(player->getX() + player->getWidth() > SCREEN_WIDTH) {
    player->setX(SCREEN_WIDTH - player->getWidth());
    player->setVelX(0);
  }

  //left side collision
  if(player->getX() < 0) {
    player->setX(0);
    player->setVelX(0);
  }


}
