#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include "object.h"

class Player : public Object {
  public:
    Player(int w, int h);
    void handle_event(SDL_Event* event) override;
};

#endif // PLAYER_H
