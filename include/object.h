// object.h
#ifndef OBJECT_H
#define OBJECT_H

#include <SDL.h>

class Object {
  protected:
    int x;
    int velX;
    int velY;
    int y;
    int width;
    int height;
  public:
    Object(int x, int y, int w, int h);
    virtual ~Object() = default;
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    void setX(int);
    void setY(int);
    int getVelX();
    int getVelY();
    void setVelX(int);
    void setVelY(int);
    void applyVelocity();
    virtual void handle_event(SDL_Event* event);
};

#endif // OBJECT_H

