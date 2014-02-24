
#include "actor.h"
#include "bum.h"
#include "game_config.h"
#include "spelling_bum.h"
#include "wrapper_factory.h"

bool SpellingBum::init() {

  libWrapper = WrapperFactory::getLibWrapper();
  if (!libWrapper->init()) {
    return false;
  }

  return true;
}

void SpellingBum::start() {

  bum = new Bum();
  bum->setPosition(GameConfig::bumStartingPosition);

  // Intialize CollisionHandler, ObstacleInjector, CollectibleInjector, ScoreBoard.

  // Start game loop here.
}

void SpellingBum::pause() {
  
}

void SpellingBum::resume() {
  
}

void SpellingBum::dispose() {
  delete libWrapper;
  delete bum;
}