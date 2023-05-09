#include <Character.h>

void Character :: Jump()
{

}


void Character :: HandleAction(SDL_Event Event)
{
    //if (rect_.y < 720) rect_.y +=Gravity;
    switch (Event.key.keysym.sym)
    {
    case SDLK_DOWN: case SDLK_s:
        rect_.y +=20;
        break;
    case SDLK_UP: case SDLK_w:
        //Jump();
        rect_.y -=20;
        break;
    case SDLK_LEFT: case SDLK_a:
        rect_.x -= 20;
        break;
    case SDLK_RIGHT: case SDLK_d:
        rect_.x += 20;
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

void Character :: Render (SDL_Renderer *gRenderer)
{
    SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
    SDL_RenderCopy(gRenderer,Texture_,NULL,&rect_);
}
bool Character :: insideScreen (int x,int y)
{
    return (rect_.x + rect_.w <= x) && (rect_.y + rect_.h <= y);
}
