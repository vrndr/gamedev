
#include "renderable.h"

Renderable::Renderable(RenderType type) {
  this->type = type;
  sprite = NULL;
}

Sprite Renderable::getSprite() const {
  return *sprite;
}

int Renderable::getClipId() const {
  return clipId;
}

Rectangle Renderable::getClip() const {
  return sprite->getClipArea(clipId);
}

void Renderable::setClipId(int clipId) {
  this->clipId = clipId;
}

void Renderable::setSprite(Sprite *sprite) {
  this->sprite = sprite;
}

void Renderable::setText(std::string text) {
  this->text = text;
}

int Renderable::getTextureId() const {
  return sprite->getTextureId();
}

RenderType Renderable::getRenderType() const {
  return type;
}

std::string Renderable::getText() const {
  return text;
}

Renderable::Builder Renderable::Builder::setRenderType(RenderType renderType) {
  this->renderType = renderType;
  return *this;
}

Renderable::Builder Renderable::Builder::setNumClipsInCol(int numClipsInCol) {
  this->numClipsInCol = numClipsInCol;
  return *this;
}

Renderable::Builder Renderable::Builder::setNumClipsInRow(int numClipsInRow) {
  this->numClipsInRow = numClipsInRow;
  return *this;
}

Renderable::Builder Renderable::Builder::setNumTotalClips(int numTotalClips) {
  this->numTotalClips = numTotalClips;
  return *this;
}

Renderable::Builder Renderable::Builder::setClipWidth(int clipWidth) {
  this->clipWidth = clipWidth;
  return *this;
}

Renderable::Builder Renderable::Builder::setClipHeight(int clipHeight) {
  this->clipHeight = clipHeight;
  return *this;
}

Renderable::Builder Renderable::Builder::setTextureFile(std::string filePath) {
  this->filePath = filePath;
  return *this;
}

Renderable::Builder Renderable::Builder::setText(std::string text) {
  this->text = text;
  return *this;
}

Renderable* Renderable::Builder::build() {
  Renderable *renderable = new Renderable(renderType);
  if (renderType == RENDER_IMAGE) {
    Sprite *sprite = new Sprite();
    sprite->build(filePath, numClipsInRow, numClipsInCol, numTotalClips,
                 clipWidth, clipHeight);

    renderable->setSprite(sprite);
    renderable->setClipId(clipId);
  } else if (renderType == RENDER_TEXT) {
    renderable->setText(text);
  }

  return renderable;
}