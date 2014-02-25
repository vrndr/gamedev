
#include <ctime>

#include "actor.h"
#include "bum.h"
#include "collectible.h"
#include "game_config.h"
#include "obstacle.h"
#include "spelling_bum.h"
#include "wrapper_factory.h"
#include "event_dispatcher.h"

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
  EventDispatcher->registerEventHandler( this, QUIT );
  isRunning = true ;

  return true;
}

void SpellingBum::handleEvent(Event* e)
{
  switch(e->getType())
  {
  case QUIT:
    this->isRunning = false ;
    break ;
  }
}


// TODO(suhas): Refactor this method.
void SpellingBum::start() {

  bum->setPosition(GameConfig::bumStartingPosition);
  stage.addActor(*bum);

  initializeEnvironment();

  // TODO(suhas): Not a right clock. Use something else.
  std::clock_t currentTime = std::clock();
  float delta = 0;

  while (isRunning) {
    // TODO(suhas): Should have a GameState that will control this while loop
    // and will also control pause and game over states.

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

    // TODO(suhas): Should be in different thread?
    inputHandler->handleInputEvents();

    collisionHandler->checkCollisions();

    camera->render(stage);

    std::clock_t previousTime = currentTime;
    currentTime = std::clock();
    delta = currentTime - previousTime;
  }
}

void SpellingBum::pause() {
  // TODO(suhas): Game loop should have states and pause / resume will change
  // these states.
}

void SpellingBum::resume() {
  
}

void SpellingBum::dispose() {
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
  camera->init();
}