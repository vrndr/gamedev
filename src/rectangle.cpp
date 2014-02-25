
#include "rectangle.h"

Rectangle::Rectangle(float x, float y, float w, float h) {
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
}

float Rectangle::getX() const {
  return x;
}

float Rectangle::getY() const {
  return y;
}

float Rectangle::getHeight() const {
  return h;
}

float Rectangle::getWidth() const {
  return w;
}

void Rectangle::set(float x, float y, float w, float h) {
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
}