
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

void Rectangle::setX(float x) {
  this->x = x;
}

void Rectangle::setY(float y) {
  this->y = y;
}

void Rectangle::setHeight(float h) {
  this->h = h;
}

void Rectangle::setWidth(float w) {
  this->w = w;
}

void Rectangle::set(float x, float y, float w, float h) {
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
}