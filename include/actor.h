#ifndef __include__actor__
#define __include__actor__

#include "base_entity.h"
#include "rectangle.h"
#include "renderable.h"

class Actor : public BaseEntity {

public:
  Actor();

  enum ActorStyle {
    PASSIVE,
    MOVING_COLLIDABLE_BLOCKING,
    MOVING_COLLIDABLE_NON_BLOCKING,
    NON_MOVING_COLLIDABLE_BLOCKING,
    NON_MOVING_COLLIDABLE_NON_BLOCKING,
    MOVING_NON_COLLIDABLE,
    NON_MOVING_NON_COLLIDABLE,
  };

  // TODO(suhas): Maybe just use Rectangle instead of all these methods.
  virtual float getX() const;
  virtual float getY() const;
  virtual float getHeight() const;
  virtual float getWidth() const;

  virtual void setX(float x);
  virtual void setY(float y);
  virtual void setHeight(float h);
  virtual void setWidth(float w);

  virtual Rectangle getPosition() const;
  virtual void setPosition(const Rectangle &position);

  virtual void handleCollision(Actor *collidedWith) {}
  virtual void update(float delta) {}

  virtual Renderable getRenderable() const;

  virtual bool isActorActive() const;
  virtual bool isActorMoving() const;
  virtual bool isActorCollidable() const;
  virtual bool isActorBlocking() const;

  virtual void setActorStyle(ActorStyle actorStyle);
  virtual void onCollision(Actor *otherActor, Rectangle *overlap);

protected:
  Renderable *renderable;

private:
  float x, y, h, w;
  bool isActive, isMoving, isCollidable, isBlocking;
};

#endif /* defined(__include__actor__) */
