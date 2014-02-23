#ifndef __include__actor__
#define __include__actor__

#include "point.h"

class Actor {
public:
  virtual float getX();
  virtual float getY();
  virtual float getHeight();
  virtual float getWidth();

  virtual void setX(float x);
  virtual void setY(float y);
  virtual void setHeight(float h);
  virtual void setWidth(float w);

  virtual void setPosition(Point p);

  virtual void handleCollision(Actor* collidedWith) {}

  virtual ~Actor() {};
  
private:
  float x, y, h, w;
};

#endif /* defined(__include__actor__) */
