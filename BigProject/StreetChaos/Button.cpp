#include <Button.h>

Button :: Button(std :: string DisplayWord)
{
    rect_.x = 0;
    rect_.y = 0;
    ColorId = {255,255,255};
    Word = DisplayWord;
}

Button :: ~Button()
{
    rect_.x = 0;
    rect_.y = 0;
    Word = "";
}

void Button :: SetColor(SDL_Color Color)
{
    ColorId = Color;
}

bool Button :: InsideButton(int x,int y)
{
    return ( x >= rect_.x ) && ( x <= rect_.x + rect_.w ) &&
                                 ( y >= rect_.y ) && ( y <= rect_.y + rect_.h );
}

void Button :: Render(SDL_Renderer *gRenderer,TTF_Font *gFont)
{
    SDL_SetRenderDrawColor(gRenderer, ColorId.r, ColorId.g, ColorId.b, 0xFF );
    SDL_RenderFillRect(gRenderer, &rect_);
    SDL_Texture *WordDisplay = loadTextureFromText(Word,{0,0,0},gFont,gRenderer);
    SDL_RenderCopy(gRenderer,WordDisplay,NULL,&rect_);
}

void Button :: RenderOtherShape(SDL_Renderer *gRenderer,TTF_Font *gFont,int Shape)
{
    SDL_SetRenderDrawColor(gRenderer, ColorId.r, ColorId.g, ColorId.b, 0xFF );
    if (Shape == TRIANGLE_RIGHT)
    {
        int p = rect_.h / rect_.w;
        int x = rect_.x;
        int y = rect_.y;
        for (int i=x;i<= x+rect_.w;i++)
        {
            SDL_RenderDrawLine(gRenderer,x,i,x+i-y+1,i);
            SDL_RenderDrawLine(gRenderer,x,rect_.h+y-(i-y),x+i-y+1,rect_.h+y-(i-y));
        }
    }
    if (Shape == TRIANGLE_LEFT)
    {
        int x = rect_.x;
        int y = rect_.y;
        for (int i=y;i<= (y + rect_.h)/2;i++)
        {
            SDL_RenderDrawLine(gRenderer,x+rect_.w-(i-y),i,x+rect_.w,i);
            SDL_RenderDrawLine(gRenderer,x+rect_.w-(i-y),rect_.h+y-(i-y),x+rect_.w,rect_.h+y-(i-y));
        }
    }
    SDL_Texture *WordDisplay = loadTextureFromText(Word,{0,0,0},gFont,gRenderer);
    SDL_RenderCopy(gRenderer,WordDisplay,NULL,&rect_);
}
