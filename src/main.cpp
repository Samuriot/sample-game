#include <SDL.h>
#include <iostream>
#include <memory>

#include "object.h"
#include "player.h"
#include "engine.h"

const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;
const int GRAVITY = 1;
const int MOVE_SPEED = 5;

void update_obj(Object* obj, int velX);
void render_obj(SDL_Renderer* renderer, Object* obj);
bool event_loop(Object* obj);
void close_SDL(SDL_Renderer* renderer, SDL_Window* window);

int main() {
  Engine game(SCREEN_WIDTH, SCREEN_HEIGHT, 16);
  game.run();
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
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    if(event.type == SDL_QUIT) {
      return false;
    }
    player->handle_event(&event);
  }
  const Uint8* keys = SDL_GetKeyboardState(NULL);
  int velX = 0;
  if(keys[SDL_SCANCODE_LEFT])
    velX -= MOVE_SPEED;
  if(keys[SDL_SCANCODE_RIGHT])
    velX += MOVE_SPEED;
  update_obj(player, velX);
  return true;
}

void update_obj(Object* obj, int velX) {
  obj->setVelX(velX);
  obj->setVelY(obj->getVelY() + GRAVITY);
  obj->applyVelocity();

  if(obj->getY() + obj->getHeight() > SCREEN_HEIGHT) {
    obj->setY(SCREEN_HEIGHT - obj->getHeight());
    obj->setVelY(0);
  }
  if(obj->getX() + obj->getWidth() > SCREEN_WIDTH) {
    obj->setX(SCREEN_WIDTH - obj->getWidth());
    obj->setVelX(0);
  }
  if(obj->getX() < 0) {
    obj->setX(0);
    obj->setVelX(0);
  }
}
