#include <Character.h>

void Character :: Jump()
{

}


void Character :: HandleAction(SDL_Event Event)
{
    switch (Event.key.keysym.sym)
    {
    case SDLK_DOWN: case SDLK_s:
        break;
    case SDLK_UP: case SDLK_w:
        Jump();
        break;
    case SDLK_LEFT: case SDLK_a:
        rect_.x -= 1;
        break;
    case SDLK_RIGHT: case SDLK_d:
        rect_.x += 1;
        break;
    case SDLK_SPACE: case SDLK_KP_0:
        break;
    }
}


bool Character :: IsDead()
{
    if (Health <= 0) return true;
    return false;
}


bool Character :: Hitbox(int x,int y)
    {
        return (x>=rect_.x && x<=(rect_.x + rect_.w)) &&
                    (y>=rect_.y && y<=(rect_.y+rect_.h));
    }
