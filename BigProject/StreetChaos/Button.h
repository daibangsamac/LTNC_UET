
#ifndef BUTTON_H_
#define BUTTON_H_

#include <BaseObject.h>

class Button : public BaseObject
{
public:

Button(std :: string DisplayWord);
~Button();
void SetColor(SDL_Color Color);
SDL_Color GetColor() const {return ColorId;}
bool InsideButton(int x,int y);
void Render(SDL_Renderer *gRenderer,TTF_Font *gFont);

protected:

SDL_Color ColorId = {255,255,255};
std :: string Word = "";

private:

};


#endif // BUTTON_H_
