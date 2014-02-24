#ifndef __include__game__
#define __include__game__

class Game {

public:
  // Initializes game and all required libraries.
  virtual bool init() = 0;

  // Starts game the game. This should be called only once to start the game.
  virtual void start() = 0;

  // Pauses game and can be resumed with resume().
  virtual void pause() = 0;

  // Resumes paused game. Does not have any effect on un-paused game.
  virtual void resume() = 0;

  // Disposes game and all libraries.
  // TODO(suhas): We may not need this as it can also be done in destructor.
  virtual void dispose() = 0;

  virtual ~Game() {};
};

#endif /* defined(__include__game__) */
