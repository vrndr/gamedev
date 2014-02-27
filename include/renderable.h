
#ifndef __include__renderable__
#define __include__renderable__

#include "sprite.h"

enum RenderType {
  RENDER_IMAGE,
  RENDER_TEXT,
  RENDER_NONE,
};

// This class contains all information about what needs to be rendered.
class Renderable {

public:
  Renderable(RenderType renderType);

  Sprite getSprite() const;
  int getClipId() const;

  void setSprite(Sprite *sprite);
  void setClipId(int clipId);

  Rectangle getClip() const;
  int getTextureId() const;

  RenderType getRenderType() const;

  class Builder {

  public:
    Builder():clipId(0) {} 
    Builder setRenderType(RenderType renderType);
    Builder setTextureFile(std::string filePath);
    Builder setNumClipsInRow(int numClipsInRow);
    Builder setNumClipsInCol(int numClipsInCol);
    Builder setNumTotalClips(int numTotalClips);
    Builder setClipWidth(int clipWidth);
    Builder setClipHeight(int clipHeight);
    Renderable* build();

  private:
    int numClipsInRow, numClipsInCol, numTotalClips, clipWidth, clipHeight;
    RenderType renderType;
    std::string filePath;
    int clipId;
  };

private:
  RenderType type;
  Sprite *sprite;
  int clipId;

  // Add fields required to render text and rendering type?
};

#endif /* defined(__include__renderable__) */
