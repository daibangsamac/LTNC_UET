#include <BaseObject.h>

BaseObject :: BaseObject()
{
    rect_.x = 0;
    rect_.y = 0;
    Texture_ = NULL;
}

BaseObject :: ~BaseObject()
{
    if (Texture_ != NULL)
    {
        SDL_DestroyTexture(Texture_);
        Texture_ = NULL;
    }
}

bool BaseObject :: loadImage(std::string path,SDL_Renderer *gRenderer)
{
    bool success = true;
    std :: string Thepath = path + "/Image_Default.png";
    Texture_ = loadTextureFromPNG(Thepath.c_str(),gRenderer);
    if (Texture_ == NULL)
    {
        printf("Failed to load Image from %s\n",path.c_str());
        success = false;
    }
    return success;
}

void BaseObject :: Render(SDL_Renderer *gRenderer)
{
    SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
    SDL_RenderCopy(gRenderer,Texture_,NULL,NULL);
}

SDL_Rect BaseObject :: Hitbox()
{
    return rect_;
}
