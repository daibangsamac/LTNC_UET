#include <Common_SDL_Func.h>


SDL_Texture *loadTextureFromPNG(std::string path)
{
    SDL_Texture * newTexture = NULL;
    SDL_Surface *loadSurface = IMG_Load(path.c_str());
    if (loadSurface == NULL)
    {
        printf( "Failed to load image %s\n",path.c_str());
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
                else
                {
                    //Initialize audio and true type font
                }
            }
        }
    }
    return success;
}

void close()
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);

    gWindow = NULL;
    gRenderer = NULL;

    IMG_Quit();
    SDL_Quit();
}

