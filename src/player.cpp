#include "player.h"

const int SCREEN_HEIGHT = 600;
const int JUMP_FORCE = -15;

Player::Player(int w, int h) : Object(0, 0, w, h) {
}

void Player::handle_event(SDL_Event* event) {
  if(event->type == SDL_KEYDOWN) {
    if(event->key.keysym.sym == SDLK_SPACE) {
      if(this->getY() + this->getHeight() >= SCREEN_HEIGHT) {
        this->setVelY(JUMP_FORCE);
      }
    }
  }
}
