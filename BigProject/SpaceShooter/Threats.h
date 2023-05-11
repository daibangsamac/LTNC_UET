#ifndef THREATS_H_
#define THREATS_H_

#include <Character.h>

enum Threat_Image
{
    Threat_Image_Red,
    Threat_Image_Green,
    Threat_Image_Total
};

static std :: string Threat_Image_Path[Threat_Image_Total] =
{
    "Threat_Image_Red",
    "Threat_Image_Green"
};

class Threat : public Character
{
    public:
    void SetPosition(int x,int y) {rect_.x = x;rect_.y = y;}
    void SetSize(int w,int h) {rect_.w = w,rect_.h = h;}
    SDL_Rect getRect() const {return rect_;}
    bool loadImage(SDL_Renderer *gRenderer);
    void HandleMovement();
    void Render (int Name,SDL_Renderer *gRenderer);
    private:
    SDL_Rect rect_;
};
#endif // THREATS_H_
