#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <BaseObject.h>

class Character : public BaseObject
{
public:
    void HandleAction(SDL_Event Event);
    bool IsDead();
    void Jump();
    void Render(SDL_Renderer *gRenderer);
    bool insideScreen(int x,int y);
protected:
    double Health = 1000.00;
    double Damage = 50.00;
    double Health_Regeneration = 0.5;
    bool object_Gravity = true;
    int Gravity = 1;
    double JumpForce = 20;
    SDL_Rect rect_ = {0,0,60,90};
private:

};


#endif // CHARACTER_H_
