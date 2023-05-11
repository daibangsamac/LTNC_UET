#ifndef RandomStuff
#define RandomStuff

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>

SDL_Texture *loadTextureFromPNG(std :: string path,SDL_Renderer *gRenderer);
SDL_Texture *loadTextureFromText(std::string textureText, SDL_Color textColor,TTF_Font *gFont,SDL_Renderer *gRenderer);

bool Init(SDL_Window **gWindow,const int SCREEN_WIDTH,const int SCREEN_HEIGHT,SDL_Renderer **gRenderer,TTF_Font **gFont,Mix_Music **gMusic);
void close(SDL_Window **gWindow,SDL_Renderer **gRenderer,TTF_Font **gFont,Mix_Music **gMusic);


#endif // COMMON_SDL_FUNCTION_H_
