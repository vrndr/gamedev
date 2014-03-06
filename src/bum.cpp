
#include "bum.h"
#include "clips_controller.h"
#include "event_dispatcher.h"
#include "game_config.h"
#include "renderable.h"
#include "renderable_factory.h"

Bum::Bum() {
  renderable = RenderableFactory->getBumRenderable();

  setActorStyle(MOVING_COLLIDABLE_BLOCKING);

  ClipsController::setClipsController(BUM_RUN, 0, 8, true);
  ClipsController::setClipsController(BUM_JUMP, 4, 4, true);
  ClipsController::setClipsController(BUM_FALL, 7, 7, true);

  state = BUM_FALL;
  floor = NULL;
  speedX = GameConfig::bumXSpeed;
  speedY = (float) 0;
  EventDispatcher->registerEventHandler(this, JUMP);
}

void Bum::update(float delta) {

  setX(getX() + speedX * delta);

  inforceGravity(delta);
  setY(getY() + speedY * delta);

  ClipsController *clipsController = ClipsController::getClipsController(state);
  renderable->setClipId(clipsController->getNextClipId(delta));
}

void Bum::inforceGravity(float delta) {
  switch (state) {
    case BUM_RUN:
      // Check floor still exists.
      if (floor == NULL || (floor->getX() + floor->getWidth()) < getX()) {
        switchStateTo(BUM_FALL);
        floor = NULL;
      }
      break;

    case BUM_JUMP:
      // Check if started falling.
      if (speedY > 0) {
        switchStateTo(BUM_FALL);
      }
      break;

    default:
      break;
  }

  speedY = speedY + delta * GameConfig::gravity;
}

void Bum::switchStateTo(State state) {
  this->state = state;
}

void Bum::onCollision(Actor *otherActor, Rectangle *overlap) {
  if (!otherActor->isActorBlocking()) {
    // Do not block on this collision.
    return;
  }

  if (overlap->getWidth() > overlap->getHeight()) {
    // Collided on Y.
    setY(overlap->getY() - getHeight());
    if (state == BUM_FALL) {
      switchStateTo(BUM_RUN);
      speedY = (float) 0;
      floor = otherActor;
    }
  } else {
    // Collided on X.
    if (getX() < overlap->getX()) {
      // Colliding from left.
      setX(overlap->getX() - getWidth());
    } else if ((getX() + getWidth()) > overlap->getX()) {
      // Colliding from right.
      setX(overlap->getX() + overlap->getWidth());
    }
  }
}

void Bum::handleEvent(Event* e) {
  switch(e->getType()) {
    case JUMP:
      if (state == BUM_RUN) {
        // Jump allowed only in run state.
        speedY = GameConfig::bumJumpSpeed;
        switchStateTo(BUM_JUMP);
      }
      break;
    default:
      break;
  }
}
