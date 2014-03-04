
#include <algorithm>

#include "actor.h"
#include "collision_handler.h"
#include "stage.h"

void CollisionHandler::init() {
  
}

bool isActiveMovingActor(Actor *actor) {
  return actor->isActorActive() && actor->isActorMoving();
}

Rectangle *getOverlaps(Actor *mainActor, Actor *otherActor) {
  if (mainActor == otherActor) {
    return NULL;
  }
  if (!otherActor->isActorCollidable()) {
    return NULL;
  }
  Rectangle mainActorRect = mainActor->getPosition();
  Rectangle otherActorRect = otherActor->getPosition();
  
  float mx1 = mainActorRect.getX();
  float my1 = mainActorRect.getY();
  float mx2 = mainActorRect.getX() + mainActorRect.getWidth();
  float my2 = mainActorRect.getY() + mainActorRect.getHeight();
  
  float ox1 = otherActorRect.getX();
  float oy1 = otherActorRect.getY();
  float ox2 = otherActorRect.getX() + otherActorRect.getWidth();
  float oy2 = otherActorRect.getY() + otherActorRect.getHeight();
  
  float xLeft = std::max(mx1, ox1);
  float xRight = std::min(mx2, ox2);
  if (xLeft > xRight) {
    return NULL;
  }

  float yTop = std::max(my1, oy1);
  float yBottom = std::min(my2, oy2);
  if (yTop > yBottom) {
    return NULL;
  }

  Rectangle *overlap = new Rectangle(xLeft, yTop, xRight - xLeft, yBottom - yTop);
  return overlap;
}

void notifyActors(Actor *mainActor, Actor *otherActor, Rectangle *overlap) {
  mainActor->onCollision(otherActor, overlap);
}

void handleCollisionsWithOtherActors(Actor *mainActor, std::list<Actor *> allActors) {
  for (std::list<Actor *>::iterator actor = allActors.begin();
       actor != allActors.end(); actor++) {
    Rectangle *overlap = getOverlaps(mainActor, *actor);
    if (overlap) {
      notifyActors(mainActor, *actor, overlap);
    }
  }
}

void CollisionHandler::checkCollisions(const Stage &stage) {
  std::list<Actor *> actors = stage.getAllActors();

  for (std::list<Actor *>::iterator actor = actors.begin();
       actor != actors.end(); actor++) {
    if (!isActiveMovingActor(*actor)) {
      continue;
    }

    handleCollisionsWithOtherActors(*actor, actors);
  }
}
