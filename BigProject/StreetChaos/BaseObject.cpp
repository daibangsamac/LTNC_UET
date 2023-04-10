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

bool BaseObject :: loadImage(std::string path)
{
    bool success = true;
    std :: string Thepath = path + "/Image_Default";
    Texture_ = loadTextureFromPNG(Thepath.c_str());
    if (Texture_ == NULL)
    {
        printf("Failed to load Image from %s\n",path.c_str());
        success = false;
    }
    return success;
}
