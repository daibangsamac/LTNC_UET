#ifndef COMMON_SDL_FUNCTION_H_
#define COMMON_SDL_FUNCTION_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

static SDL_Window *gWindow = NULL;
static SDL_Renderer *gRenderer = NULL;

SDL_Texture *loadTextureFromPNG(std :: string path);


bool Init();
void close();


#endif // COMMON_SDL_FUNCTION_H_
