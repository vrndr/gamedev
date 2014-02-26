
#ifndef __include__sprite__
#define __include__sprite__

#include <string>
#include <vector>

#include "rectangle.h"

// Maybe this can be just moved to renderable?
class Sprite {

public:
  int getTextureId() const;
  Rectangle getClipArea(int clipId) const;

  void build(std::string filePath, int numClipsInRow, int numClipsInCol,
      int numTotalClips, float clipWidth, float clipHeight);

private:
  int textureId;
  std::vector<Rectangle *> clips;

  void buildClips(int numClipsInRow, int numClipsInCol,
      int numTotalClips, int clipWidth, int clipHeight);
};

#endif /* defined(__include__sprite__) */
