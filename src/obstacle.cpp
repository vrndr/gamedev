
#include "obstacle.h"

Obstacle::Obstacle() {
  renderable = Renderable::Builder()
      .setRenderType(RenderType::RENDER_IMAGE)
      .setTextureFile("assets/obstacle.png")
      .setNumClipsInRow(1)
      .setNumClipsInCol(1)
      .setNumTotalClips(1)
      .setClipWidth(250)
      .setClipHeight(250)
      .build();
  setActorStyle(NON_MOVING_COLLIDABLE_BLOCKING);
}
