// object.h
#ifndef OBJECT_H
#define OBJECT_H

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
};

#endif // OBJECT_H

