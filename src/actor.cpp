
#include "actor.h"

Actor::Actor() {
  isStatic = false;
  isPassive = false;

  renderable = new Renderable(RenderType::RENDER_NONE);
}

float Actor::getX() const {
  return x;
}

float Actor::getY() const {
  return y;
}

float Actor::getHeight() const {
  return h;
}

float Actor::getWidth() const {
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

Rectangle Actor::getPosition() const {
  return Rectangle(x, y, w, h);
}

void Actor::setPosition(const Rectangle &position) {
  setX(position.getX());
  setY(position.getY());
  setWidth(position.getWidth());
  setHeight(position.getHeight());
}

bool Actor::isStaticActor() const {
  return isStatic;
}

bool Actor::isPassiveActor() const {
  return isPassive;
}

void Actor::setAsStaticActor() {
  isStatic = true;
}

void Actor::setAsPassiveActor() {
  isPassive = true;
}

Renderable Actor::getRenderable() const {
  return *renderable;
}