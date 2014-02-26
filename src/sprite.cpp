
#include "lib_wrapper.h"
#include "sprite.h"
#include "wrapper_factory.h"

int Sprite::getTextureId() const {
  return textureId;
}

Rectangle Sprite::getClipArea(int clipId) const {
  return *clips.at(clipId);
}

void Sprite::build(std::string filePath, int numClipsInRow, int numClipsInCol,
    int numTotalClips, float clipWidth, float clipHeight) {
  LibWrapper *libWrapper = WrapperFactory::getLibWrapper();
  textureId = libWrapper->createTexture(filePath);

  buildClips(numClipsInRow, numClipsInCol, numTotalClips, clipWidth, clipHeight);
}

void Sprite::buildClips(int numClipsInRow, int numClipsInCol,
    int numTotalClips, int clipWidth, int clipHeight) {
  for (int i = 0; i < numClipsInCol; ++i) {
    for (int j = 0; j < numClipsInRow; j++) {
      Rectangle *newClip = new Rectangle();
      if (((i * numClipsInRow) + j) >= numTotalClips) {
        break;
      }
      newClip->setX(j * clipWidth);
      newClip->setY(i * clipHeight);
      newClip->setWidth(clipWidth);
      newClip->setHeight(clipHeight);

      clips.push_back(newClip);
    }
  }
}
