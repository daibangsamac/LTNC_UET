#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <BaseObject.h>


class Character : public BaseObject
{
public:
    void HandleAction(SDL_Event Event);
    bool IsDead();
    bool Hitbox(int x,int y);
    void Jump();

protected:
    double Health = 1000.00;
    double Damage = 50.00;
    double Health_Regeneration = 0.5;
    bool object_Gravity = true;
    double Gravity = 0.6;
    double JumpForce = 20;

private:

};


#endif // CHARACTER_H_
