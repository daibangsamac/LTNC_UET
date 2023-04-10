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

bool Background :: loadImage(std::string path)
{
    bool success = true;
    for (int i=0;i<Image_Background_Total;i++)
    {
        std :: string Thepath = path + "/Background/" + Image_Background_Path[i];
        Texture_[i] = loadTextureFromPNG(Thepath);
        if (Texture_[i] == NULL)
        {
            success = false;
            printf("Failed to load Image %s\n",Thepath.c_str());
        }
    }
    return success;
}
