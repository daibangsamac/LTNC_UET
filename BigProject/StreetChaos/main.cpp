
#include <Common_SDL_Function.h>
#include <iostream>
#include <Button.h>
#include <Background.h>
#include <Character.h>

using namespace std;

extern const int SCREEN_WIDTH = 1280;
extern const int SCREEN_HEIGHT = 720;

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
SDL_Event gEvent;
TTF_Font *gFont = NULL;
Mix_Music *gMusic = NULL;

extern const SDL_Color RGB_COLOR = {255, 255, 255};
extern const  SDL_Color Colors[] = { {255, 0, 0},  {0, 255, 0},  {0, 0, 255}};
extern const int COLORS = sizeof(Colors) / sizeof(SDL_Color);


enum Action
{
    QUIT,
    PAUSE,
    MENU,
    CHOOSING_CHARACTER_1stPLAYER,
    CHOOSING_CHARECTER_2ndPLAYER,
    CHOOSING_MAP,
    INGAME,
    ENDGAME,
    DEFAULT
};


int main(int argc,char *argv[])
{
    int Session = MENU;
    if (!Init(&gWindow,SCREEN_WIDTH,SCREEN_HEIGHT,&gRenderer,&gFont,&gMusic))
    {
        printf("Failed to initialized\n");
    }
    else
    {
        Background gBackground;
        gBackground.SetPosition(0,0);
        gBackground.SetSize(SCREEN_WIDTH,SCREEN_HEIGHT);
        gBackground.loadImage(gRenderer);
        /////////////////////////////////////////////////

        Button Menu_Start = Button("Start");
        Menu_Start.SetSize(80,40);
        Menu_Start.SetPosition(600,320);
        Menu_Start.SetColor({177,235,52});
        Button Menu_Exit = Button ("Exit");
        bool quit = false;
        while (!quit)
        {
            SDL_Delay(10);
            cout << "-";
            while (SDL_PollEvent(&gEvent))
            {
                switch (Session)
                    {
                    case MENU:
                        {Button Menu_Start = Button("Start");
                        Menu_Start.SetSize(80,40);
                        Menu_Start.SetPosition(600,320);
                        Menu_Start.SetColor({177,235,52});
                        Button Menu_Exit = Button ("Exit");
                        Menu_Exit.SetSize(80,40);
                        Menu_Exit.SetPosition(600,400);
                        Menu_Exit.SetColor({177,235,52});
                        SDL_RenderClear(gRenderer);
                        gBackground.Render(Image_Background_Menu,gRenderer);
                        Menu_Start.Render(gRenderer,gFont);
                        Menu_Exit.Render(gRenderer,gFont);
                        if (gEvent.type == SDL_MOUSEBUTTONDOWN && gEvent.button.button == SDL_BUTTON_LEFT)
                        {
                            int x,y;
                            SDL_GetMouseState(&x,&y);
                            if (Menu_Start.InsideButton(x,y)) Session = CHOOSING_CHARACTER_1stPLAYER;
                            if (Menu_Exit.InsideButton(x,y)) {Session = QUIT;quit = true;}
                        }
                        }
                        break;
                    case PAUSE:
                        continue;
                        break;
                    case QUIT:
                        quit = true;
                        continue;
                        break;
                    case CHOOSING_CHARACTER_1stPLAYER:
                        SDL_Delay(1000);                      ////chua xong
                        Session = QUIT;                       ////chua xong
                        quit = true;
                        break;
                    case CHOOSING_CHARECTER_2ndPLAYER:
                        break;
                    case CHOOSING_MAP:
                        break;
                    case INGAME:
                        break;
                    case ENDGAME:
                        break;
                    }
                if (gEvent.type == SDL_QUIT) {Session = QUIT;quit = true;}
            }
            SDL_RenderPresent(gRenderer);
        }
    }
    close(&gWindow,&gRenderer,&gFont,&gMusic);
    return 0;
}

