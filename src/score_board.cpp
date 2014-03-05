
#include "score_board.h"

ScoreBoard::ScoreBoard() {
  renderable = Renderable::Builder()
      .setRenderType(RenderType::RENDER_TEXT)
      .setText("Score: " + std::to_string(score))
      .build();

  setActorStyle(PASSIVE);
}

void ScoreBoard::updateScore(int addScore) {
  score = score + addScore;
  renderable->setText("Score: " + std::to_string(score));
}
