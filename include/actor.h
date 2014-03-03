#ifndef __include__actor__
#define __include__actor__

#include "base_entity.h"
#include "rectangle.h"
#include "renderable.h"

class Actor : public BaseEntity {

public:
  enum PositioningStyle {
    STATIC,
    WITH_CAMERA,
  };

  enum CollisionStyle {
    COLLIDABLE_BLOCKING,
    COLLIDABLE_NON_BLOCKING,
    NON_COLLIDABLE,
  };

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

  virtual Renderable getRenderable() const;

  virtual PositioningStyle getPositioningStyle();
  virtual CollisionStyle getCollisionStyle();

  virtual void setPositioningStyle(PositioningStyle positioningStyle);
  virtual void setCollisionStyle(CollisionStyle collisionStyle);

  virtual ~Actor() {};

protected:
  Renderable *renderable;

private:
  float x, y, h, w;
  PositioningStyle positioningStyle;
  CollisionStyle collisionStyle;
};

#endif /* defined(__include__actor__) */
