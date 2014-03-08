
#include <stdlib.h>
#include <time.h>

#include "event_dispatcher.h"
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

    remainingChars.push_back(c);

    stage->addActor(character);
    characterNum++;
  }
  this->camera = camera;
  EventDispatcher->registerEventHandler(this, OBJECT_COLLECTED);
  srand((unsigned) time(NULL));
}

char GameTracker::getNewCharacter() {
  int random = rand() % 100;
  if (random < 60) {
    return 'A' + (rand() % 26);
  }

  if (remainingChars.size() == 0) {
    return '%'; // Error.
  }
  random = rand() % (remainingChars.size());
  std::list<char>::iterator it = remainingChars.begin();
  for (int i = 0; i < random; i++, it++) {}

  return *it;
}

void GameTracker::handleEvent(Event* e) {
  switch (e->getType()) {
    case OBJECT_COLLECTED: {
      bool found = false;
      for (GameWordCharacter *c : gameCharacters) {
        if (c->isHidden()
            && c->getCharacter() == e->getEventData()->collectedCharacter) {
          c->markFound();
          found = true;
          for (std::list<char>::iterator it = remainingChars.begin();
              it != remainingChars.end(); it++) {
            if (*it == c->getCharacter()) {
              remainingChars.erase(it);
              checkGameOverCondition();
              break;
            }
          }
          scoreBoard->updateScore(20);
          break;
        }
      }
      if (!found) {
        scoreBoard->updateScore(-10);
      }
      break;
    }
      
    default:
      break;
  }
}

void GameTracker::checkGameOverCondition() {
  if (remainingChars.size() == 0) {
    Event *e = new Event(EventType::GAME_OVER);
    EventDispatcher->dispatchEvent(e);
  }
}