
#include "bum.h"
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
}

void Bum::update(float delta) {
  
  /**** Code for testing. Should be deleted ****/
  static int i = 0;
  i++;
  if (i >= 8) {
    i = 0;
    int clipId = renderable->getClipId() + 1;
    if (clipId >= 8) {
      clipId = 0;
    }
    renderable->setClipId(clipId);
  }
  setX(getX() + 1);
  /**** Code for testing. Should be deleted ****/
}