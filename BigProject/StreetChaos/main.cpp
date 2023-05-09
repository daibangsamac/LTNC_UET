
#include <Common_SDL_Function.h>
#include <iostream>
#include <Button.h>
#include <Background.h>
#include <Character.h>
#include <Board.h>

using namespace std;

extern const int SCREEN_WIDTH = 1280;
extern const int SCREEN_HEIGHT = 720;

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
SDL_Event gEvent;
TTF_Font *gFont = NULL;
Mix_Music *gMusic = NULL;

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
        Background gBackground = Background();
        gBackground.SetPosition(0,0);
        gBackground.SetSize(SCREEN_WIDTH,SCREEN_HEIGHT);
        gBackground.loadImage(gRenderer);

        Character Menu_Character = Character();
        Menu_Character.SetPosition(500,400);
        Menu_Character.SetSize(60,90);
        Menu_Character.loadImage("Image/Character",gRenderer);
        /////////////////////////////////////////////////

        bool quit = false;
        while (!quit)
        {
            if (Session == QUIT) {quit = true;}
            while (Session == MENU)
            {
                SDL_Delay(10);
                cout << "-";
                Button Menu_Start = Button("Start");
                Menu_Start.SetSize(80,40);
                Menu_Start.SetPosition(600,400);
                Menu_Start.SetColor({177,235,52});

                Button Menu_Exit = Button ("Exit");
                Menu_Exit.SetSize(80,40);
                Menu_Exit.SetPosition(600,480);
                Menu_Exit.SetColor({177,235,52});

                while (SDL_PollEvent(&gEvent))
                {
                if (gEvent.type == SDL_QUIT) {Session = QUIT;quit = true;}
                Menu_Character.HandleAction(gEvent);
                if (gEvent.type == SDL_MOUSEBUTTONDOWN && gEvent.button.button == SDL_BUTTON_LEFT)
                {
                    int x,y;
                    SDL_GetMouseState(&x,&y);
                    if (Menu_Start.InsideButton(x,y)) Session = CHOOSING_CHARACTER_1stPLAYER;
                    if (Menu_Exit.InsideButton(x,y)) {Session = QUIT;quit = true;}
                }
                }

                SDL_RenderClear(gRenderer);
                gBackground.Render(Image_Background_Menu,gRenderer);
                Menu_Character.Render(gRenderer);
                Menu_Start.Render(gRenderer,gFont);
                Menu_Exit.Render(gRenderer,gFont);
                SDL_RenderPresent(gRenderer);
            }
            while (Session == CHOOSING_CHARACTER_1stPLAYER)
            {
                SDL_Delay(10);
                cout << "-";
                Board Choosing_Character1st_Board = Board();
                Choosing_Character1st_Board.SetPosition(SCREEN_WIDTH/4,SCREEN_HEIGHT/4);
                Choosing_Character1st_Board.SetSize(640,360);

                Button Button_Next = Button("");
                Button_Next.SetPosition(4,4);
                Button_Next.SetSize(100,200);
                Button_Next.SetColor({177,235,52});

                Button Button_Previous = Button("");
                Button_Previous.SetPosition(SCREEN_WIDTH/4,SCREEN_HEIGHT/4);
                Button_Previous.SetSize(100,200);
                Button_Previous.SetColor({177,235,52});

                while (SDL_PollEvent(&gEvent))
                {
                if (gEvent.type == SDL_QUIT) {Session = QUIT;quit = true;}
                }


                SDL_RenderClear(gRenderer);
                gBackground.Render(Image_Background_ChoosingCharacter,gRenderer);
                Choosing_Character1st_Board.Render(gRenderer);
                Button_Next.RenderOtherShape(gRenderer,gFont,TRIANGLE_RIGHT);
                Button_Previous.RenderOtherShape(gRenderer,gFont,TRIANGLE_LEFT);
                SDL_RenderPresent(gRenderer);
            }
                    /*case PAUSE:
                        continue;
                        break;
                    case QUIT:
                        quit = true;
                        continue;
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
            }*/
        }
    }
    close(&gWindow,&gRenderer,&gFont,&gMusic);
    return 0;
}

