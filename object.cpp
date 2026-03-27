#include "object.h"

Object::Object(int x, int y, int w, int h) {
  this->x = x;
  this->y = y;
  this->width = w;
  this->height = h;
}

int Object::getX() {
  return this->x;
}

int Object::getY() {
  return this->y;
}

int Object::getWidth() {
  return this->width;
}

int Object::getHeight() {
  return this->height;
}

void Object::setX(int x) { 
  if(x <= 0)
    this->x = 0;
  else 
    this->x = x;
}

void Object::setY(int y) { 
  if(y <= 0)
    this->y = 0;
  else 
    this->y = y;
}

void Object::incrementX() {
  this->x++;
}

void Object::incrementY() {
  this->y++;
}

void Object::decrementX() {
  this->x--;
}

void Object::decrementY() {
  this->y--;
}

