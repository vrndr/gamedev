
#ifndef __include__game_tracker__
#define __include__game_tracker__

#include <list>

#include "base_entity.h"
#include "camera.h"
#include "score_board.h"
#include "game_word_character.h"
#include "timer_display.h"

class GameTracker : public BaseEntity {

public:
  void init(Camera *camera, Stage *stage);
  char getNewCharacter();
  void handleEvent(Event* e);

private:
  ScoreBoard *scoreBoard;
  TimerDisplay *timerDisplay;
  std::list<GameWordCharacter *> gameCharacters;
  Camera *camera;
  std::list<char> remainingChars;
};

#endif /* defined(__include__game_tracker__) */
