#include <Threats.h>


bool Threat :: loadImage(SDL_Renderer *gRenderer)
{
    bool success = true;
    for (int i=0;i<Threat_Image_Total;i++)
    {
        std :: string Thepath ="Image/Threat/" + Threat_Image_Path[i] + ".png";
        Texture_[i] = loadTextureFromPNG(Thepath,gRenderer);
        if (Texture_[i] == NULL)
        {
            success = false;
            printf("Failed to load Image %s\n",Thepath.c_str());
        }
    }
    return success;
}

void Threat :: HandleMovement()
{
    rect_.y+=2;
    if (rect_.y>720) rect_.y=0;
}

void Threat :: Render (int Name,SDL_Renderer *gRenderer)
{
    SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
    SDL_Rect RenderQuad = rect_;
    SDL_RenderCopy(gRenderer,Texture_[Name],NULL,&RenderQuad);
}
