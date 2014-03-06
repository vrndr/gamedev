
#include "score_board.h"

ScoreBoard::ScoreBoard() {
  score = 0;
  renderable = Renderable::Builder()
      .setRenderType(RenderType::RENDER_TEXT)
      .setText("Score: " + std::to_string(score))
      .build();

  setActorStyle(PASSIVE);
}

void ScoreBoard::updateScore(int points) {
  score = score + points;
  renderable->setText("Score: " + std::to_string(score));
}
