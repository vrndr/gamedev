
#ifndef __include__game_config__
#define __include__game_config__

#include "rectangle.h"

// All configuration constants go here.
namespace GameConfig {

  // TODO(suhas): Should be externs?
  const Rectangle bumStartingPosition(100, 300, 96, 80);
  const float bumXPositionOnScreen = (float) 100;
  const float bumXSpeed = (float) 150;

  const float screenWidth = (float) 640;
  const float screenHeight = (float) 480;

  const float gravity = (float) 250;  // pixels per second.
};

#endif /* defined(__include__game_config__) */
