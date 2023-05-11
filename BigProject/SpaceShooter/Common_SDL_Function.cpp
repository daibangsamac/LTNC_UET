#include <Common_SDL_Function.h>


SDL_Texture *loadTextureFromPNG(std::string path,SDL_Renderer *gRenderer)
{
    SDL_Texture *newTexture = NULL;
    SDL_Surface *loadSurface = IMG_Load(path.c_str());
    if (loadSurface == NULL)
    {
        printf( "Failed to load image %s\n",path.c_str());
    }
    else
    {
        SDL_SetColorKey( loadSurface, SDL_TRUE, SDL_MapRGB( loadSurface->format, 0xFF, 0xFF, 0xFF ) );
        newTexture = SDL_CreateTextureFromSurface(gRenderer,loadSurface);
        if (newTexture == NULL)
        {
            printf("Failed to convert image to texture. Error: %s\n",SDL_GetError());
        }
        SDL_FreeSurface(loadSurface);
    }
    return newTexture;
}


SDL_Texture *loadTextureFromText(std::string textureText,SDL_Color textColor,TTF_Font *gFont,SDL_Renderer *gRenderer)
{
    SDL_Texture *TextTexture = NULL;
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    if (textureText != "")
    if( textSurface == NULL )
    {
        printf( "Failed to render text surface!\n");
    }
    else
    {
        TextTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
        if (TextTexture == NULL)
        {
            printf( "Failed to render text texture from surface!\n");
        }
        SDL_FreeSurface(textSurface);
    }
    return TextTexture;
}

bool Init(SDL_Window **gWindow,const int SCREEN_WIDTH,const int SCREEN_HEIGHT,SDL_Renderer **gRenderer,TTF_Font **gFont,Mix_Music **gMusic)
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) <0 )
    {
        printf("Failed to initialized\n");
        success = false;
    }
    else
    {
        *gWindow = SDL_CreateWindow("SpaceRunner",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if (*gWindow == NULL)
        {
            printf("Failed to create window\n");
            success = false;
        }
        else
        {
            *gRenderer = SDL_CreateRenderer(*gWindow,-1,SDL_RENDERER_ACCELERATED);
            if (*gRenderer == NULL)
            {
                printf("Failed to create renderer\n");
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(*gRenderer,0xFF,0xFF,0xFF,0xFF);
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf("Failed to initialized SDL_image\n");
                    success = false;
                }
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "Failed to initialized SDL_mixer\n" );
                    success = false;
                }
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf\n" );
                    success = false;
                }
                *gFont = TTF_OpenFont("Freedom-10eM.ttf",20);
                if( gFont == NULL )
                    {
                        printf( "Failed to load Freedom font\n" );
                        success = false;
                    }
            }
        }
    }
    return success;
}


void close(SDL_Window **gWindow,SDL_Renderer **gRenderer,TTF_Font **gFont,Mix_Music **gMusic)
{

    // Free Global Variables
    SDL_DestroyRenderer(*gRenderer);
    SDL_DestroyWindow(*gWindow);
    TTF_CloseFont( *gFont );
    Mix_FreeMusic(* gMusic );


    *gWindow = NULL;
    *gRenderer = NULL;
    *gFont = NULL;
    *gMusic = NULL;


    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
    Mix_Quit();


}
