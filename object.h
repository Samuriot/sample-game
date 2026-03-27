// object.h
#ifndef OBJECT_H
#define OBJECT_H

class Object {
  private:
    int x;
    int y;
    int width;
    int height;
    int speed;
  public:
    Object(int x, int y, int w, int h, int speed = 10);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    void setX(int);
    void setY(int);
    void incrementX();
    void incrementY();
    void decrementX();
    void decrementY();
};

#endif // OBJECT_H

