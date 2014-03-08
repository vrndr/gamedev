
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
  gameTracker = new GameTracker();
  camera = new Camera();
  EventDispatcher->registerEventHandler(this, QUIT);
  EventDispatcher->registerEventHandler(this, GAME_OVER);
  isRunning = true ;

  return true;
}

void SpellingBum::handleEvent(Event* e) {
  switch(e->getType()) {

    case QUIT:
      this->isRunning = false ;
      break ;

    case GAME_OVER:
      this->isRunning = false;
      break;

    default:
      break;
  }
}


// TODO(suhas): Refactor this method.
void SpellingBum::start() {

  initializeEnvironment();

  bum->setPosition(GameConfig::bumStartingPosition);
  stage.addActor(bum);
  camera->followActor(bum);

  unsigned currentTime = libWrapper->getCurrentTime();
  float delta = 0;

  while (isRunning) {
    // TODO(suhas): Should have a GameState that will control this while loop
    // and will also control pause and game over states.

    std::cout << "New delta " << delta << " time " << currentTime << " Bum: " << bum->getX() << "\n";

    // update all actors.
    std::list<Actor *> allActors = stage.getAllActors();
    for (std::list<Actor *>::iterator actor = allActors.begin();
        actor != allActors.end(); actor++) {
      (*actor)->update(delta);
    }

    // TODO(suhas): Should we make CollectibleHandler / ObstacleHandlers as
    // Actors. These are actually group of Actors.
    collectibleHandler->update(*camera);
    obstacleHandler->update(*camera);

    collisionHandler->checkCollisions(stage);

    // TODO(suhas): Should be in different thread?
    inputHandler->handleInputEvents();

    camera->update();
    camera->render(stage);

    unsigned previousTime = currentTime;
    currentTime = libWrapper->getCurrentTime();
    delta = (float)(currentTime - previousTime);
    delta = delta / 1000;
    if (delta > 0.1) {
      delta = (float) 0.1;
    }
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
  obstacleHandler->initializeCollectibles(&stage);
  collectibleHandler->initializeCollectibles(&stage, gameTracker);
  collisionHandler->init();
  inputHandler->init();
  gameTracker->init(camera, &stage);
  camera->init();
}