#include "player.h"
#include <SDL.h>

Player::Player(int w, int h) : Object(0, 0, w, h) {
  
}

void handle_event(SDL_Event& event) {
  if(event.type == SDL_KEYDOWN) {
    if(event.key.keysym.sym == SDLK_SPACE) {
      // Only jump if on the ground
      if(this->getY() + this->getHeight() >= SCREEN_HEIGHT) {
        this->setVelY(JUMP_FORCE);
      }
    }
  } 
}
