// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Player : public Object {
  public:
    Player(int w, int h);
    void handle_event(SDL_Event& event);
};

#endif // OBJECT_H

