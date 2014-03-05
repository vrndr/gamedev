
#ifndef __include__game_config__
#define __include__game_config__

#include <string>

#include "rectangle.h"

// All configuration constants go here.
namespace GameConfig {

  // TODO(suhas): Should be externs?
  const Rectangle bumStartingPosition(100, 100, 96, 80);
  const float bumXPositionOnScreen = (float) 100;
  const float bumXSpeed = (float) 150;
  const float bumJumpSpeed = (float) -200;

  const float screenWidth = (float) 640;
  const float screenHeight = (float) 480;

  const float gravity = (float) 250;  // pixels per second.

  const std::string gameWord = "SPELL";
  const float gameWordDisplayWidth = (float) 200;
  const float gameWordCharacterSize = (float) 30;
  const float gameWordCharacterY = (float) 30;

  const Rectangle scoreBoardPosition(500, 20, 80, 25);
};

#endif /* defined(__include__game_config__) */
