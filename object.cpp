#include "object.h"

Object::Object(int x, int y, int w, int h) {
  this->x = x;
  this->velX = 0;
  this->y = y;
  this->velY = 0;
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

int Object::getVelX() {
  return this->velX;
}

int Object::getVelY() {
  return this->velY;
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

void Object::setVelX(int v) {
  this->velX = v;
}

void Object::setVelY(int v) {
  this->velY = v;
}

void Object::applyVelocity() {
  this->x += this->velX;
  this->y += this->velY;
}

