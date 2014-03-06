
#ifndef __include__renderable_factory__
#define __include__renderable_factory__

#include "renderable.h"

class __RenderableFactory {

public:
  static __RenderableFactory* getInstance() {
    static __RenderableFactory factory;
    return &factory;
  }

  Renderable *getBumRenderable();
  Renderable *getObstacleRenderable();
  Renderable *getCollectibleRenderable(char c);

private:
  __RenderableFactory();  // private constructor.

  Renderable *bumRenderable;
  Renderable *obstacleRenderable;
  Renderable *gameCharacterRenderable;
};

#define RenderableFactory __RenderableFactory::getInstance()

#endif /* defined(__include__renderable_factory__) */
