
#include "actor.h"

float Actor::getX() {
  return x;
}

float Actor::getY() {
  return y;
}

float Actor::getHeight() {
  return h;
}

float Actor::getWidth() {
  return w;
}

void Actor::setX(float x) {
  this->x = x;
}

void Actor::setY(float y) {
  this->y = y;
}

void Actor::setHeight(float h) {
  this->h = h;
}

void Actor::setWidth(float w) {
  this->w = w;
}

void Actor::setPosition(Point p) {
  setX(p.getX());
  setY(p.getY());
}