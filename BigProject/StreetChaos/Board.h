#ifndef BOARD_H_
#define BOARD_H_

#include <BaseObject.h>


class Board : public BaseObject
{
public:
void Render(SDL_Renderer *gRenderer);

protected:
SDL_Color ColorID = {0,0,0};


private:

};



#endif
