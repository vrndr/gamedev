
#include "actor.h"

Actor::Actor() {
  setActorStyle(NON_MOVING_NON_COLLIDABLE);
  
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

bool Actor::isActorActive() const {
  return isActive;
}

bool Actor::isActorMoving() const {
  return isMoving;
}

bool Actor::isActorCollidable() const {
  return isCollidable;
}

bool Actor::isActorBlocking() const {
  return isBlocking;
}

void Actor::setActorStyle(ActorStyle actorStyle) {
  switch (actorStyle) {
    case PASSIVE:
      isActive = false;
      isMoving = false;
      isCollidable = false;
      isBlocking = false;
      break;
    case MOVING_COLLIDABLE_BLOCKING:
      isActive = true;
      isMoving = true;
      isCollidable = true;
      isBlocking = true;
      break;
    case MOVING_COLLIDABLE_NON_BLOCKING:
      isActive = true;
      isMoving = true;
      isCollidable = true;
      isBlocking = false;
      break;
    case MOVING_NON_COLLIDABLE:
      isActive = true;
      isMoving = true;
      isCollidable = false;
      isBlocking = false;
      break;
    case NON_MOVING_COLLIDABLE_BLOCKING:
      isActive = true;
      isMoving = false;
      isCollidable = true;
      isBlocking = true;
      break;
    case NON_MOVING_COLLIDABLE_NON_BLOCKING:
      isActive = true;
      isMoving = false;
      isCollidable = true;
      isBlocking = false;
      break;
    case NON_MOVING_NON_COLLIDABLE:
      isActive = true;
      isMoving = false;
      isCollidable = false;
      isBlocking = false;
      break;
  }
}

Renderable Actor::getRenderable() const {
  return *renderable;
}

void Actor::onCollision(Actor *otherActor, Rectangle *overlap) {
  
}
