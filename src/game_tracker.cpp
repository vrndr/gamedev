
#include "game_config.h"
#include "game_tracker.h"

void GameTracker::init(Camera *camera, Stage *stage) {
  scoreBoard = new ScoreBoard();
  scoreBoard->setPosition(GameConfig::scoreBoardPosition);
  stage->addActor(scoreBoard);
  std::string gameWord = GameConfig::gameWord;
  float characterWidth = GameConfig::gameWordDisplayWidth / gameWord.length();

  float gameWordDisplayX =
      (GameConfig::screenWidth - GameConfig::gameWordDisplayWidth) / 2;

  int characterNum = 0;
  for (char &c : gameWord) {
    GameWordCharacter *character = new GameWordCharacter(c);
    gameCharacters.push_back(character);

    character->setWidth(GameConfig::gameWordCharacterSize);
    character->setHeight(GameConfig::gameWordCharacterSize);
    character->setY(GameConfig::gameWordCharacterY);
    character->setX(gameWordDisplayX + characterWidth * characterNum);

    stage->addActor(character);
    characterNum++;
  }
  this->camera = camera;
}

void GameTracker::getNewCharacter() {
  
}

void GameTracker::handleEvent(Event* e) {
  switch (e->getType()) {
    case OBJECT_COLLECTED:
      for (GameWordCharacter *c : gameCharacters) {
        if (c->isHidden()
            && c->getCharacter() == e->getEventData().collectedCharacter) {
          c->markFound();
          scoreBoard->updateScore(20);
          break;
        }
      }
      break;
      
    default:
      break;
  }
}

