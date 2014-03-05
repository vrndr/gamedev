
#ifndef __include__score_board__
#define __include__score_board__

#include "actor.h"

class ScoreBoard : public Actor {

public:
  ScoreBoard();
  void updateScore(int addScore);

private:
  int score;
};

#endif /* defined(__include__score_board__) */
