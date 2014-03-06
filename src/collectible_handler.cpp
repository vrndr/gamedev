
#include "collectible_handler.h"

void CollectibleHandler::initializeCollectibles(Stage *stage,
                                             GameTracker *gameTracker) {
  this->stage = stage;
  this->gameTracker = gameTracker;
  lastCollectiblePositionX = 0;
}

void CollectibleHandler::update(const Camera &camera) {

  char character = gameTracker->getNewCharacter();

  /*** Only for testing. Update me. *******/
   
  float cameraX = camera.getCameraPosition().getX();
  if (cameraX > (lastCollectiblePositionX)) {
    Collectible *collectible = new Collectible(character);
    Rectangle collectiblePosition(cameraX + 900, 300, 30, 40);
    collectible->setPosition(collectiblePosition);

    stage->addActor(collectible);
    lastCollectiblePositionX = collectible->getX();
  }
  /*** Only for testing. Update me. *******/
}
