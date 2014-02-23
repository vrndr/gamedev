
#include <iostream>

#include "game.h"
#include "spelling_bum.h"

int main(int argc, const char * argv[]) {
  Game *spellingBum = new SpellingBum();

  spellingBum->init();
  spellingBum->start();

  std::cout << "Hello, World!!!!\n";
  return 0;
}

