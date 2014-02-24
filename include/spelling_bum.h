#ifndef __include__spelling_bum__
#define __include__spelling_bum__

#include "actor.h"
#include "collectible_handler.h"
#include "collision_handler.h"
#include "game.h"
#include "input_handler.h"
#include "lib_wrapper.h"
#include "obstacle_handler.h"
#include "stage.h"

class SpellingBum : public Game {

public:
  // Initializes game and all required libraries.
  bool init();
  
  // Starts game the game. This should be called only once to start the game.
  void start();
  
  // Pauses game and can be resumed with resume().
  void pause();
  
  // Resumes paused game. Does not have any effect on un-paused game.
  void resume();
  
  // Disposes game and all libraries.
  // TODO(suhas): We may not need this as it can also be done in destructor.
  void dispose();

private:
  LibWrapper *libWrapper;
  Actor *bum;
  ObstacleHandler *obstacleHandler;
  CollectibleHandler *collectibleHandler;
  CollisionHandler *collisionHandler;
  InputHandler *inputHandler;
  Camera *camera;

  Stage stage;

  void initializeEnvironment();
};

#endif /* defined(__include__spelling_bum__) */
