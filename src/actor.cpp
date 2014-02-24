
#include "actor.h"

Actor::Actor() {
  isStatic = false;
  isPassive = false;
}

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

Rectangle Actor::getPosition() {
  return Rectangle(x, y, w, h);
}

void Actor::setPosition(Rectangle p) {
  setX(p.getX());
  setY(p.getY());
}

bool Actor::isStaticActor() {
  return isStatic;
}

bool Actor::isPassiveActor() {
  return isPassive;
}

void Actor::setAsStaticActor() {
  isStatic = true;
}

void Actor::setAsPassiveActor() {
  isPassive = true;
}