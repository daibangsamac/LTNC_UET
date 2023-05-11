#ifndef BaseObject_H_
#define BaseObject_H_

#include <Common_SDL_Function.h>

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();

    bool loadImage(std :: string path,SDL_Renderer *gRenderer);
    void SetPosition(int x,int y) {rect_.x = x;rect_.y = y;}
    void SetSize(int w,int h) {rect_.w = w,rect_.h = h;}
    SDL_Rect getRect() const {return rect_;}
    SDL_Rect Hitbox();
    void Render(SDL_Renderer *gRenderer);
    void HandleCollision();

protected:
    SDL_Rect rect_;
    bool object_Gravity = false;
    SDL_Texture *Texture_ = NULL;

private:

};

#endif //BaseObject_h_
