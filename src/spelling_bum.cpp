
#include <ctime>

#include "actor.h"
#include "bum.h"
#include "collectible.h"
#include "game_config.h"
#include "obstacle.h"
#include "spelling_bum.h"
#include "wrapper_factory.h"

bool SpellingBum::init() {

  libWrapper = WrapperFactory::getLibWrapper();
  if (!libWrapper->init()) {
    return false;
  }

  bum = new Bum();
  obstacleHandler = new ObstacleHandler();
  collectibleHandler = new CollectibleHandler();
  collisionHandler = new CollisionHandler();
  inputHandler = new InputHandler();
  camera = new Camera();
  return true;
}

void SpellingBum::start() {

  bum->setPosition(GameConfig::bumStartingPosition);

  initializeEnvironment();

  // TODO(suhas): Not a right clock. Use something else.
  std::clock_t currentTime = std::clock();
  float delta = 0;
  
  while (1) {

    std::cout << "New delta " << delta << " time " << currentTime << "\n";

    // update all actors.
    std::list<Actor> allActors = stage.getAllActors();

    for (std::list<Actor>::iterator actor = allActors.begin();
        actor != allActors.end(); actor++) {
      actor->update(delta);
    }

    // TODO(suhas): Should we make CollectibleHandler / ObstacleHandlers as
    // Actors. These are actually group of Actors.
    collectibleHandler->update(*camera);
    obstacleHandler->update(*camera);

    collisionHandler->checkCollisions();

    // Render stage with camera.

    std::clock_t previousTime = currentTime;
    currentTime = std::clock();
    delta = currentTime - previousTime;
  }
}

void SpellingBum::pause() {
  
}

void SpellingBum::resume() {
  
}

void SpellingBum::dispose() {
  delete libWrapper;
  delete bum;
  delete obstacleHandler;
  delete collectibleHandler;
  delete collisionHandler;
  delete inputHandler;
  delete camera;
}

void SpellingBum::initializeEnvironment() {
  obstacleHandler->initializeCollectibles(stage);
  collectibleHandler->initializeObstacles(stage);
  collisionHandler->init();
  inputHandler->init();
}