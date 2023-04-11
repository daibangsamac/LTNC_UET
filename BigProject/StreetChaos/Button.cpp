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
    SDL_SetRenderDrawColor(gRenderer, ColorId.r, ColorId.g, ColorId.b, 0 );
    SDL_RenderFillRect(gRenderer, &rect_);
    SDL_Texture *WordDisplay = loadTextureFromText(Word,{0,0,0},gFont,gRenderer);
    SDL_RenderCopy(gRenderer,WordDisplay,NULL,&rect_);
}
