
#include "game_word_character.h"

GameWordCharacter::GameWordCharacter(char c) {
  this->character = c;
  hidden = true;

  renderable = Renderable::Builder()
      .setRenderType(RenderType::RENDER_IMAGE)
	  .setTextureFile("assets/obstacle.png")
      .setNumClipsInRow(1)
      .setNumClipsInCol(1)
      .setNumTotalClips(1)
      .setClipWidth(250)
      .setClipHeight(250)
      .build();

  setActorStyle(PASSIVE);
}

char GameWordCharacter::getCharacter() {
  return character;
}

bool GameWordCharacter::isHidden() {
  return hidden;
}

void GameWordCharacter::markFound() {
  hidden = false;
  std::string text(1, character);
  renderable = Renderable::Builder()
      .setRenderType(RenderType::RENDER_TEXT)
      .setText(text)
      .build();
}
