#ifndef __include__actor__
#define __include__actor__

#include "rectangle.h"
#include "base_entity.h"

class Actor : public BaseEntity {

public:
  Actor();

  // TODO(suhas): Maybe just use Rectangle instead of all these methods.
  virtual float getX();
  virtual float getY();
  virtual float getHeight();
  virtual float getWidth();

  virtual void setX(float x);
  virtual void setY(float y);
  virtual void setHeight(float h);
  virtual void setWidth(float w);

  virtual Rectangle getPosition();
  virtual void setPosition(Rectangle p);

  virtual void handleCollision(Actor* collidedWith) {}
  virtual void update(float delta) {}

  virtual void setAsStaticActor();
  virtual void setAsPassiveActor();

  virtual bool isStaticActor();
  virtual bool isPassiveActor();

  virtual ~Actor() {};

private:
  float x, y, h, w;
  bool isStatic, isPassive;
};

#endif /* defined(__include__actor__) */
