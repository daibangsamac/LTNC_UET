#include <Background.h>

Background :: Background()
{
    rect_.x = 0;
    rect_.y = 0;
    for (int i=0;i<Image_Background_Total;i++)
    Texture_[i] = NULL;
}

Background :: ~Background()
{
    for (int i=0;i<Image_Background_Total;i++)
    if (Texture_[i] != NULL)
    {
        SDL_DestroyTexture(Texture_[i]);
        Texture_[i] = NULL;
    }
}

bool Background :: loadImage(SDL_Renderer *gRenderer)
{
    bool success = true;
    for (int i=0;i<Image_Background_Total;i++)
    {
        std :: string Thepath ="Image/Background/" + Image_Background_Path[i] + ".png";
        Texture_[i] = loadTextureFromPNG(Thepath,gRenderer);
        if (Texture_[i] == NULL)
        {
            success = false;
            printf("Failed to load Image %s\n",Thepath.c_str());
        }
    }
    return success;
}

void Background :: Render(int Name,SDL_Renderer *gRenderer)
{
    SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
    SDL_RenderCopy(gRenderer,Texture_[Name],NULL,NULL);
}

