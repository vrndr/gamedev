
#ifndef __include__game_config__
#define __include__game_config__

#include "rectangle.h"

// All configuration constants go here.
namespace GameConfig {

  // TODO(suhas): Should be externs?
  const Rectangle bumStartingPosition(100, 300, 96, 80);

  const float screenWidth = 640;
  const float screenHeight = 480;
};

#endif /* defined(__include__game_config__) */
