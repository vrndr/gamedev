
#include "rectangle.h"

Rectangle::Rectangle(float x, float y, float w, float h) {
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
}

float Rectangle::getX() {
  return x;
}

float Rectangle::getY() {
  return y;
}

float Rectangle::getHeight() {
  return h;
}

float Rectangle::getWidth() {
  return w;
}

void Rectangle::set(float x, float y, float w, float h) {
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
}