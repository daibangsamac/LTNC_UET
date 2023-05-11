#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <BaseObject.h>
enum Character_Image
{
    Character_Image_Default,
    Character_Image_Dead,
    Character_Image_Total
};
static std:: string Character_Image_Path[Character_Image_Total]=
{
    "Character_Image_Default",
    "Character_Image_Dead"
};

class Character : public BaseObject
{
public:
    void SetPosition(int x,int y) {rect_.x = x;rect_.y = y;}
    void SetSize(int w,int h) {rect_.w = w,rect_.h = h;}
    SDL_Rect getRect() const {return rect_;}
    void HandleAction(SDL_Event Event);
    bool insideScreen(int x,int y);
    bool loadImage(SDL_Renderer *gRenderer);
    void Render(int Name,SDL_Renderer *gRenderer);
    bool Hitbox();
protected:
    SDL_Texture *Texture_[Character_Image_Total];
    SDL_Rect rect_;
private:

};


#endif // CHARACTER_H_
