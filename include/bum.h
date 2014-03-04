#ifndef __include__bum__
#define __include__bum__

#include "actor.h"

class Bum : public Actor {
public:
  enum State {
    BUM_RUN,
    BUM_JUMP,
    BUM_FALL,
    STATE_MAX,
  };

  Bum();
  void update(float delta);
  void onCollision(Actor *otherActor, Rectangle *overlap);
  // Handles events dispatched to this object
  void handleEvent(Event* e);

private:
  void inforceGravity(float delta);
  void switchStateTo(State state);

  State state;
  Actor *floor;

  // TODO(suhas): Replace with Vector?
  float speedX, speedY;  // speed in pixels per second.
};

#endif /* defined(__include__bum__) */
