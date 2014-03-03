
#include "bum.h"
#include "clips_controller.h"
#include "game_config.h"
#include "renderable.h"

Bum::Bum() {
  renderable = Renderable::Builder()
      .setRenderType(RenderType::RENDER_IMAGE)
      .setTextureFile("assets/bum.png")
      .setNumClipsInRow(4)
      .setNumClipsInCol(5)
      .setNumTotalClips(20)
      .setClipWidth(192)
      .setClipHeight(160)
      .build();

  ClipsController::setClipsController(BUM_RUN, 0, 8, true);
  ClipsController::setClipsController(BUM_JUMP, 4, 4, true);
  ClipsController::setClipsController(BUM_FALL, 8, 8, true);

  state = BUM_RUN;
  speedX = GameConfig::bumXSpeed;
  speedY = (float) 0;
}

void Bum::update(float delta) {

  setX(getX() + speedX * delta);

  inforceGravity();
  if (state != BUM_FALL && speedY > 0) {
    switchStateTo(BUM_FALL);
  }
  setY(getY() + speedY * delta);

  ClipsController *clipsController = ClipsController::getClipsController(state);
  renderable->setClipId(clipsController->getNextClipId(delta));
}

void Bum::inforceGravity() {
  
}

void Bum::switchStateTo(State state) {
  
}