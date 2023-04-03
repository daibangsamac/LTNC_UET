#include <SDL_image.h>
#include <SDL.h>
#include <cstdio>
#include <iostream>
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
enum Image
{
    Image_Default,
    Image_Victory,
    Image_Victory2,
    Image_Lower,
    Image_Higher,
    Image_Total
};
SDL_Window *gWindow = NULL;

SDL_Renderer *gRenderer = NULL;

SDL_Texture *gTexture[Image_Total];
bool Init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO<0))
    {
        printf("Failed to initialized\n");
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow("Guess It",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_RESIZABLE);
        if (gWindow == NULL)
        {
            printf("Failed to create window\n");
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Failed to create renderer\n");
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf("Failed to initialized SDL_image\n");
                    success = false;
                }
            }
        }
    }
    return success;
}
SDL_Texture *loadTexture( std::string path)
{
    SDL_Texture * newTexture = NULL;
    SDL_Surface *loadSurface = IMG_Load(path.c_str());
    if (loadSurface == NULL)
    {
        printf( "Failed to load image\n");
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(gRenderer,loadSurface);
        if (newTexture == NULL)
        {
            printf("Failed to convert image to texture\n");
        }
        SDL_FreeSurface(loadSurface);
    }
    return newTexture;
}
bool loadMedia()
{
    bool success = true;
    gTexture[Image_Default] = loadTexture("Image/Image_Default.png");
    if (gTexture[Image_Default]==NULL)
    {
        printf("Failed to load Image Default\n");
        success = false;
    }
    gTexture[Image_Victory] = loadTexture("Image/Image_Victory.png");
    if (gTexture[Image_Victory]==NULL)
    {
        printf("Failed to load Image Victory\n");
        success = false;
    }
    gTexture[Image_Victory2] = loadTexture("Image/Image_Victory2.png");
    if (gTexture[Image_Victory2]==NULL)
    {
        printf("Failed to load Image Victory2\n");
        success = false;
    }
    gTexture[Image_Lower] = loadTexture("Image/Image_Lower.png");
    if (gTexture[Image_Lower]==NULL)
    {
        printf("Failed to load Image Lower\n");
        success = false;
    }
    gTexture[Image_Higher] = loadTexture("Image/Image_Higher.png");
    if (gTexture[Image_Higher]==NULL)
    {
        printf("Failed to load Image Higher\n");
        success = false;
    }
    return success;
}
void close()
{
    for (int i=0;i<Image_Total;i++)
        {
            SDL_DestroyTexture(gTexture[i]);
            gTexture[i] = NULL;
        }
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    IMG_Quit();
    SDL_Quit();
}
