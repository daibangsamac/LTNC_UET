#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <BaseObject.h>


enum Image_Background
{
    Image_Background_Menu,
    Image_Background_ChoosingCharacter,
    Image_Background_Total
};


static std :: string Image_Background_Path[Image_Background_Total] =
{
    "Image_Background_Menu",
    "Image_Background_ChoosingCharacter"
};


class Background : public BaseObject
{
public:
Background();
~Background();
bool loadImage(SDL_Renderer *gRenderer);
void Render(int Name,SDL_Renderer *gRenderer);

protected:
SDL_Texture *Texture_[Image_Background_Total];

private:

};



#endif // BACKGROUND_H_
