#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <time.h>
#include <SDL_ttf.h>
#include <cstdio>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
bool loadMedia();
bool Init();
void close();
SDL_Texture *loadTexture(std :: string path)
{
    SDL_Texture *optimizedTexture = NULL;
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s\n",path.c_str());
    }
    else
    {
        optimizedTexture = SDL_CreateTextureFromSurface(gRenderer,loadedSurface);
        if (optimizedTexture == NULL)
        {
            printf("Failed to convert image to texture\n");
        }
        SDL_FreeSurface(loadedSurface);
    }
    return optimizedTexture;
}
class object
{
    public:
    object();
    ~object();
    void Show();
    void setRect(int x,int y) {rect_.x = x; rect_.y = y;};
    SDL_Rect getRect() const {return rect_;};
    bool loadIMG();
    protected:
    enum Image_
    {
        Image_Default,
        Image_Total
    };
    std :: string IMGpath_[Image_Total+1]=
    {
        "Image_Default",
        "Object"
    };
    SDL_Rect rect_;
    SDL_Texture *Texture_ [Image_Total];
};
class background : public object
{
    public:
    bool loadIMG()
    {
        std :: string path = IMGpath_[Image_Total];
        bool success = true;
        for (int i=0;i<Image_Total;i++)
            {
                std :: string pathImg = path + "\\" + IMGpath_[i];
                Texture_[i] = loadTexture(pathImg);
                if (Texture_[i] == NULL)
                {
                    printf ("Failed to load %s\n",pathImg.c_str());
                success = false;
                }
            }
    return success;
    }
    protected:
    enum Image_
    {
        Image_Default,
        something,
        moresomething,
        Image_Total
    };
    std :: string IMGpath_[Image_Total+1]=
    {
        "Image_Default",
        "something",
        "moresomething",
        "Background"
    };
} gBackground = background();
class body : public object
{
    public:
    bool loadIMG()
    {
        std :: string path = IMGpath_[Image_Total];
        bool success = true;
        for (int i=0;i<Image_Total;i++)
            {
                std :: string pathImg = path + "\\" + IMGpath_[i];
                Texture_[i] = loadTexture(pathImg);
                if (Texture_[i] == NULL)
                {
                    printf ("Failed to load %s\n",pathImg.c_str());
                success = false;
                }
            }
    return success;
    }
    protected:
    enum Image_
    {
        Image_Default,
        something,
        moresomething,
        Image_Total
    };
    std :: string IMGpath_[Image_Total+1]=
    {
        "Image_Default",
        "something",
        "moresomething",
        "Body"
    };
} gBody = body();
class gallow : public object
{
    public:
    bool loadIMG()
    {
        std :: string path = IMGpath_[Image_Total];
        bool success = true;
        for (int i=0;i<Image_Total;i++)
            {
                std :: string pathImg = path + "\\" + IMGpath_[i];
                Texture_[i] = loadTexture(pathImg);
                if (Texture_[i] == NULL)
                {
                    printf ("Failed to load %s\n",pathImg.c_str());
                success = false;
                }
            }
    return success;
    }
    protected:
    enum Image_
    {
        Image_Default,
        something,
        moresomething,
        Image_Total
    };
    std :: string IMGpath_[Image_Total+1]=
    {
        "Image_Default",
        "something",
        "moresomething",
        "Gallow"
    };
} gGallow =gallow();
object :: object()
{
    rect_.x = 0;
    rect_.y = 0;
    for (int i=0;i<Image_Total;i++)
    {
        Texture_[i] = NULL;
    }
}
object :: ~object()
{
    for (int i=0;i<Image_Total;i++)
    {
        if (Texture_[i] != NULL)
        {
            SDL_DestroyTexture(Texture_[i]);
            Texture_[i] = NULL;
        }
    }
}
bool object :: loadIMG()
{
    std :: string path = IMGpath_[Image_Total];
    bool success = true;
    for (int i=0;i<Image_Total;i++)
    {
        std :: string pathImg = path + "\\" + IMGpath_[i];
        Texture_[i] = loadTexture(pathImg);
        if (Texture_[i] == NULL)
        {
            printf ("Failed to load %s\n",pathImg.c_str());
            success = false;
        }
    }
    return success;
}
void object :: Show(SDL_Texture *TheTexture)
{
    SDL_Rect rect = getRect();
    SDL_RenderClear( gRenderer );
    SDL_RenderCopy( gRenderer, gTexture[ImageShown], NULL, NULL );
    SDL_RenderPresent(gRenderer);
}
bool Init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO)<0)
    {
        printf("Unable to initialize SDL\n");
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow("Hangman",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_RESIZABLE);
        if (gWindow == NULL)
        {
            printf("Unable to create window\n");
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf ("Unable to create renderer\n");
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf("Unable to initialize SDL_image\n");
                    success = false;
                }
                else
                {
                    // Audio
                    // True type fonts
                }
            }
        }
    }
    return success;
}
bool loadMedia()
{
    bool success = true;
    if (!gBackground .loadIMG())
    {
        printf("Unable to load Background\n");
        success = false;
    }
    if (!gBody.loadIMG())
    {
        printf("Unable to load Body\n");
        success = false;
    }
    if (gGallow.loadIMG())
    {
        printf ("Unable to load Gallow\n");
        success = false;
    }
    return success;
}
void close()
{
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;
    SDL_Quit();
    IMG_Quit();
}
