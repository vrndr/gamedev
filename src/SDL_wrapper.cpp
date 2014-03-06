#include <iostream>

#include "game_config.h"
#include "SDL_image.h"
#include "sdl_wrapper.h"

using namespace std ;

SDL_Rect* toSdlRect(const Rectangle &rectangle) {
  SDL_Rect *sdlRect = new SDL_Rect();
  sdlRect->x = rectangle.getX();
  sdlRect->y = rectangle.getY();
  sdlRect->w = rectangle.getWidth();
  sdlRect->h = rectangle.getHeight();
  return sdlRect;
}

bool SdlWrapper::init() {

  // TODO (Veerendra): return meaningful error values

  if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
    cout << SDL_GetError() << endl;
    return false;
  }

  if (TTF_Init() == -1){
    std::cout << TTF_GetError() << std::endl;
    return 2;
  }

  window = SDL_CreateWindow("SpellingBum", SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED, GameConfig::screenWidth, GameConfig::screenHeight,
      SDL_WINDOW_SHOWN);
  if (window == nullptr){
    cout << "SDL CreateWindow error" << SDL_GetError() << endl;
    return false;
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
      SDL_RENDERER_PRESENTVSYNC);
  if (renderer == nullptr){
    cout << SDL_GetError() << endl;
    return false;
  }

  font = TTF_OpenFont("assets/DejaVuSans.ttf", 15);
  if (font == nullptr) {
    std::cout << "OpenFont error: " << SDL_GetError() << std::endl;
  }
  SDL_RenderClear(renderer);
  return true;
}

void SdlWrapper::startRendering() {
  SDL_RenderClear(renderer);
}

void SdlWrapper::finishRendering() {
  SDL_RenderPresent(renderer);
}

void SdlWrapper::render(const Renderable &renderable,
    const Rectangle &position) {

  switch (renderable.getRenderType()) {
    case RENDER_IMAGE: {
      SDL_Texture *texture = textures.at(renderable.getTextureId());
      SDL_Rect *srcRect = toSdlRect(renderable.getClip());
      SDL_Rect *destRect = toSdlRect(position);
      SDL_RenderCopy(renderer, texture, srcRect, destRect);
      delete srcRect;
      delete destRect;
      break;
    }

    case RENDER_TEXT: {
      SDL_Color color = { 255, 255, 255 };
      SDL_Surface *surface = TTF_RenderText_Blended(font,
          renderable.getText().c_str(), color);
      if (surface == nullptr) {
        std::cout << "RenderText error: " << SDL_GetError() << std::endl;
      }
      SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
      if (texture == nullptr) {
        std::cout << "CreateTexture error: " << SDL_GetError() << std::endl;
      }
      SDL_FreeSurface(surface);

      SDL_Rect *destRect = toSdlRect(position);
      SDL_RenderCopy(renderer, texture, NULL, destRect);
      SDL_DestroyTexture(texture);
      delete destRect;
      break;
    }

    case RENDER_NONE:
      break;
  }
}

Event* SdlWrapper::getInputEvent() {
  Event *e;
  SDL_Event sdlEvent;
  SDL_PollEvent(&sdlEvent);

  switch (sdlEvent.type) {

    case SDL_QUIT:
      e = new Event(QUIT);
      break;

    case SDL_KEYDOWN:
      if (sdlEvent.key.keysym.sym == SDLK_SPACE) {
        e = new Event(JUMP);
      } else {
        e = new Event(NONE);
      }
      break;

    // Handle other events like touch.
    default:
      e = new Event(NONE);
  }

  return e;
}

int SdlWrapper::createTexture(const std::string &fileName) {
  SDL_Texture *sdlTexture = IMG_LoadTexture(renderer, fileName.c_str());
  if (sdlTexture == nullptr) {
    std::cout << "LoadTexture error: " << SDL_GetError() << std::endl;
  }

  textures.push_back(sdlTexture);
  return (int) textures.size() - 1;
}

unsigned SdlWrapper::getCurrentTime() {
  return SDL_GetTicks();
}
