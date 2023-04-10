#ifndef BASEOBJECT_H_
#define BASEOBJECT_H_


#include <Common_SDL_Func.h>

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();

    bool loadImage(std :: string path);
    void SetRect(int x,int y) {rect_.x = x;rect_.y = y;}
    SDL_Rect getRect() const {return rect_;}

protected:
    SDL_Rect rect_;
    SDL_Texture *Texture_ = NULL;

private:

};



#endif //BASEOBJECT_H_
