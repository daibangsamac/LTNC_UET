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
SDL_Texture *loadTexture(std::string path)
{
    SDL_Texture *newTexture = NULL;
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
            printf("Failed to convert image to texture. Error: %s\n",SDL_GetError());
        }
        SDL_FreeSurface(loadSurface);
    }
    return newTexture;
}
class object
{
    public:
    object();
    ~object();
    void Show(int i);
    void setRect(int x,int y) {rect_.x = x; rect_.y = y;};
    SDL_Rect getRect() const {return rect_;};
    bool loadIMG();
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
    protected:

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
        std :: string pathImg = path + "/" + IMGpath_[i] + ".png";
        Texture_[i] = loadTexture(pathImg);
        if (Texture_[i] == NULL)
        {
            printf ("Unable to load %s\n",pathImg.c_str());
            success = false;
        }
    }
    return success;
    }
    enum Image_
    {
        Image_Default,
        Image_Total
    };
    protected:

    std :: string IMGpath_[Image_Total+1]=
    {
        "Image_Default",
        "Image/Background"
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
        std :: string pathImg = path + "/" + IMGpath_[i] + ".png";
        Texture_[i] = loadTexture(pathImg);
        if (Texture_[i] == NULL)
        {
            printf ("Unable to load %s\n",pathImg.c_str());
            success = false;
        }
    }
    return success;
    }
    enum Image_
    {
        Image_Default,
        Image_head,
        Image_Neck,
        Image_Body,
        Image_Arm_left,
        Image_Arm_right,
        Image_Leg_left,
        Image_leg_right,
        Image_Total
    };
    protected:

    std :: string IMGpath_[Image_Total+1]=
    {
        "Image_Default",
        "Image_head",
        "Image_Neck",
        "Image_Body",
        "Image_Arm_left",
        "Image_Arm_right",
        "Image_Leg_left",
        "Image_leg_right",
        "Image/Body"
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
        std :: string pathImg = path + "/" + IMGpath_[i] + ".png";
        Texture_[i] = loadTexture(pathImg);
        if (Texture_[i] == NULL)
        {
            printf ("Unable to load %s\n",pathImg.c_str());
            success = false;
        }
            }
    return success;
    }
    enum Image_
    {
        Image_Default,
        Image_Total
    };
    protected:

    std :: string IMGpath_[Image_Total+1]=
    {
        "Image_Default",
        "Image/Gallow"
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
        std :: string pathImg = path + "/" + IMGpath_[i] + ".png";
        Texture_[i] = loadTexture(pathImg);
        if (Texture_[i] == NULL)
        {
            printf ("Unable to load %s\n",pathImg.c_str());
            success = false;
        }
    }
    return success;
}
void object :: Show(int i)
{
    SDL_Texture *TheTexture = Texture_[i];
    //SDL_Rect rect = getRect();
    SDL_RenderClear( gRenderer );
    SDL_RenderCopy( gRenderer, TheTexture, NULL, NULL );
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
        gWindow = SDL_CreateWindow("Hangman",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
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
    if (!gGallow.loadIMG())
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
