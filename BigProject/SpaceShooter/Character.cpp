#include <Character.h>

bool Character :: loadImage(SDL_Renderer *gRenderer)
{
    bool success = true;
    for (int i=0;i<Character_Image_Total;i++)
    {
        std :: string Thepath ="Image/Character/" + Character_Image_Path[i] + ".png";
        Texture_[i] = loadTextureFromPNG(Thepath,gRenderer);
        if (Texture_[i] == NULL)
        {
            success = false;
            printf("Failed to load Image %s\n",Thepath.c_str());
        }
    }
    return success;
}
void Character :: HandleAction(SDL_Event Event)
{
    if (Event.type == SDL_MOUSEMOTION)
    {
        int x,y;
        SDL_GetMouseState(&x,&y);
        rect_.x = x - rect_.w/2;
        rect_.y = y - rect_.h/2;
    }
}

void Character :: Render (int Name,SDL_Renderer *gRenderer)
{
    SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
    SDL_Rect RenderQuad = rect_;
    SDL_RenderCopy(gRenderer,Texture_[Name],NULL,&RenderQuad);
}

bool Character :: insideScreen (int x,int y)
{
    return (rect_.x + rect_.w <= x) && (rect_.y + rect_.h <= y);
}

