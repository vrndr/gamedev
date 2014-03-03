
#include "actor.h"

Actor::Actor() {
  positioningStyle = WITH_CAMERA;
  collisionStyle = COLLIDABLE_NON_BLOCKING;
  
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

Actor::PositioningStyle Actor::getPositioningStyle() {
  return positioningStyle;
}

void Actor::setPositioningStyle(Actor::PositioningStyle positioningStyle) {
  this->positioningStyle = positioningStyle;
}

Actor::CollisionStyle Actor::getCollisionStyle() {
  return collisionStyle;
}

void Actor::setCollisionStyle(Actor::CollisionStyle collisionStyle) {
  this->collisionStyle = collisionStyle;
}

Renderable Actor::getRenderable() const {
  return *renderable;
}