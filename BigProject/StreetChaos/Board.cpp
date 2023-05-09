
#include <Board.h>


void Board :: Render (SDL_Renderer *gRenderer)
{
    SDL_SetRenderDrawColor(gRenderer,ColorID.r,ColorID.g,ColorID.b,0xFF - 100);
    SDL_SetRenderDrawBlendMode(gRenderer,SDL_BLENDMODE_BLEND);
    SDL_RenderFillRect(gRenderer,&rect_);
}
