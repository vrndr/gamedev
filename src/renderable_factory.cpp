
#include "renderable_factory.h"

__RenderableFactory::__RenderableFactory() {
  bumRenderable = NULL;
  obstacleRenderable = NULL;
  gameCharacterRenderable = NULL;
}

Renderable * __RenderableFactory::getBumRenderable() {
  if (!bumRenderable) {
    bumRenderable = Renderable::Builder()
        .setRenderType(RenderType::RENDER_IMAGE)
        .setTextureFile("assets/bum.png")
        .setNumClipsInRow(4)
        .setNumClipsInCol(5)
        .setNumTotalClips(20)
        .setClipWidth(192)
        .setClipHeight(160)
        .build();
  }
  return bumRenderable;
}

Renderable * __RenderableFactory::getObstacleRenderable() {
  if (!obstacleRenderable) {
    obstacleRenderable = Renderable::Builder()
        .setRenderType(RenderType::RENDER_IMAGE)
        .setTextureFile("assets/obstacle.png")
        .setNumClipsInRow(1)
        .setNumClipsInCol(1)
        .setNumTotalClips(1)
        .setClipWidth(250)
        .setClipHeight(250)
        .build();
  }
  return obstacleRenderable;
}

Renderable * __RenderableFactory::getCollectibleRenderable(char c) {
  return NULL;
}

