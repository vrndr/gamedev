#ifndef __include__actor__
#define __include__actor__

#include "rectangle.h"

class Actor {

public:
  Actor();

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

  virtual void setAsStaticActor();
  virtual void setAsPassiveActor();

  virtual bool isStaticActor() const;
  virtual bool isPassiveActor() const;

  virtual ~Actor() {};

private:
  float x, y, h, w;
  bool isStatic, isPassive;
};

#endif /* defined(__include__actor__) */
