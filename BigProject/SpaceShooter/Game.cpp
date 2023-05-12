#include <Common_SDL_Function.h>
#include <iostream>
#include <Button.h>
#include <Background.h>
#include <Character.h>
#include <Threats.h>
#include <cstdlib>
#include <time.h>
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
    INGAME,
    ENDGAME,
    DEFAULT
};

int dd[6],Cooldown[6]={0,20,40,6,7,12};
void HandleOtherMovement(Background &TBackground,Threat &TEnemy1,Threat &TEnemy2,Threat &TEnemy3,Threat &TEnemy4,Threat &TEnemy5)
{
    SDL_Rect temp = TBackground.getRect();
    if (temp.y>=0) TBackground.SetPosition(temp.x,720-2000);
    else TBackground.SetPosition(temp.x,temp.y+3);

    if (dd[1]==0)
    {if (Cooldown[1]==0)
    {
        dd[1]=(rand()*123 + rand()*157 + rand()*159)%2;
        if (dd[1])
        {int temp = (rand()*123 + rand()*157 + rand()*159) %1200;
        TEnemy1.SetPosition(temp,0);
        }
    } else Cooldown[1]--;}
    if (dd[2]==0)
    {if (Cooldown[2]==0)
    {
        dd[2]=(rand()*213 + rand()*277 + rand()*259)%2;
        if (dd[2])
        {int temp = (rand()*213 + rand()*277 + rand()*259) %1200;
        TEnemy2.SetPosition(temp,0);
        }
    } else Cooldown[2]--;}
    if (dd[3]==0)
    {if (Cooldown[3]==0)
    {
        dd[3]=(rand()*313 + rand()*317 + rand()*279)%2;
        if (dd[3])
        {int temp = (rand()*313 + rand()*317 + rand()*279) %1200;
        TEnemy3.SetPosition(temp,0);
        }
    } else Cooldown[3]--;}
    if (dd[4]==0)
    {if (Cooldown[4]==0)
    {
        dd[4]=(rand()*23 + rand()*37 + rand()*79)%2;
        if (dd[4])
        {int temp = (rand()*23 + rand()*37 + rand()*79) %1200;
        TEnemy4.SetPosition(temp,0);
        }
    }  else Cooldown[4]--;}
    if (dd[5]==0)
    {if (Cooldown[5]==0)
    {
        dd[5]=(rand()*25 + rand()*39 + rand()*49)%2;
        if (dd[5])
        {int temp = (rand()*25 + rand()*39 + rand()*49) %1200;
        TEnemy5.SetPosition(temp,0);
        }
    } else Cooldown[5]--;}


    if (dd[1]==1)TEnemy1.HandleMovement();
    if (dd[2]==1)TEnemy2.HandleMovement();
    if (dd[3]==1)TEnemy3.HandleMovement();
    if (dd[4]==1)TEnemy4.HandleMovement();
    if (dd[5]==1)TEnemy5.HandleMovement();


    SDL_Rect Temp1 = TEnemy1.getRect();
    if (Temp1.y==0) {dd[1] = 0;Cooldown[1]=(rand()*123+321*rand())%40;}
    SDL_Rect Temp2 = TEnemy2.getRect();
    if (Temp2.y==0) {dd[2] = 0;Cooldown[2]=(rand()*123+321*rand())%40;}
    SDL_Rect Temp3 = TEnemy3.getRect();
    if (Temp3.y==0) {dd[3] = 0;Cooldown[3]=(rand()*123+321*rand())%40;}
    SDL_Rect Temp4 = TEnemy4.getRect();
    if (Temp4.y==0) {dd[4] = 0;Cooldown[4]=(rand()*123+321*rand())%40;}
    SDL_Rect Temp5 = TEnemy5.getRect();
    if (Temp5.y==0) {dd[5] = 0;Cooldown[5]=(rand()*123+321*rand())%40;}


}
bool Collide (SDL_Rect Object1,SDL_Rect Object2)
{
    int temp1 = Object1.x;
    int temp2 = Object1.x + Object1.w;
    int temp3 = Object1.y;
    int temp4 = Object1.y + Object1.h;

    if (temp1<=Object2.x && Object2.x <=temp2)
    {
        if (temp3 <=Object2.y && Object2.y <= temp4) return true;
        if (temp3 <=(Object2.y+Object2.h) && (Object2.y+Object2.h)<=temp4) return true;
    }

    if (temp1<=(Object2.x+Object2.w) && (Object2.x+Object2.w) <=temp2)
    {
        if (temp3 <=Object2.y && Object2.y <= temp4) return true;
        if (temp3 <=(Object2.y+Object2.h) && (Object2.y+Object2.h)<=temp4) return true;
    }
    return false;
}
bool HandleCollision(Character &Player,Threat &Enemy1,Threat &Enemy2,Threat &Enemy3,Threat &Enemy4,Threat &Enemy5)
{
    SDL_Rect PlayerHitBox = Player.getRect();
    SDL_Rect Enemy1HitBox = Enemy1.getRect();
    SDL_Rect Enemy2HitBox = Enemy2.getRect();
    SDL_Rect Enemy3HitBox = Enemy3.getRect();
    SDL_Rect Enemy4HitBox = Enemy4.getRect();
    SDL_Rect Enemy5HitBox = Enemy5.getRect();

    if (dd[1]&&Collide(PlayerHitBox,Enemy1HitBox)) return true;
    if (dd[2]&&Collide(PlayerHitBox,Enemy2HitBox)) return true;
    if (dd[3]&&Collide(PlayerHitBox,Enemy3HitBox)) return true;
    if (dd[4]&&Collide(PlayerHitBox,Enemy4HitBox)) return true;
    if (dd[5]&&Collide(PlayerHitBox,Enemy5HitBox)) return true;
    return false;
}
int main(int argc,char *argv[])
{
    int Session = MENU;
    srand(time(NULL));
    if (!Init(&gWindow,SCREEN_WIDTH,SCREEN_HEIGHT,&gRenderer,&gFont,&gMusic))
    {
        printf("Failed to initialized\n");
    }
    else
    {
        int Timer;
        SDL_Color ColWord = {63, 196, 176};
        SDL_Texture *SpaceShooter = loadTextureFromText("Space Runner",ColWord,gFont,gRenderer);


        Background gBackground = Background();
        gBackground.SetPosition(0,0);
        gBackground.SetSize(SCREEN_WIDTH,SCREEN_HEIGHT);
        gBackground.loadImage(gRenderer);

        Button Menu_Start = Button("Start");
        Menu_Start.SetSize(80,40);
        Menu_Start.SetPosition(600,400);
        Menu_Start.SetColor({177,235,52});

        Button Menu_Exit = Button ("Exit");
        Menu_Exit.SetSize(80,40);
        Menu_Exit.SetPosition(600,480);
        Menu_Exit.SetColor({177,235,52});
        /////////////////////////////////////////////////

        Character Player = Character();
        Player.SetPosition(0,0);
        Player.SetSize(80,120);
        Player.loadImage(gRenderer);

        Threat Enemy1,Enemy2,Enemy3,Enemy4,Enemy5;
        Enemy1.loadImage(gRenderer);
        Enemy1.SetPosition(0,0);
        Enemy1.SetSize(80,120);

        Enemy2.loadImage(gRenderer);
        Enemy2.SetPosition(0,0);
        Enemy2.SetSize(80,120);

        Enemy3.loadImage(gRenderer);
        Enemy3.SetPosition(0,0);
        Enemy3.SetSize(80,120);

        Enemy4.loadImage(gRenderer);
        Enemy4.SetPosition(0,0);
        Enemy4.SetSize(80,120);

        Enemy5.loadImage(gRenderer);
        Enemy5.SetPosition(0,0);
        Enemy5.SetSize(80,120);

        //////////////////////////////////////////
        Button Endgame_Retry = Button("Retry");
        Endgame_Retry.SetSize(80,40);
        Endgame_Retry.SetPosition(600,400);
        Endgame_Retry.SetColor({177,235,52});


        Button Endgame_Exit = Button("Exit");
        Endgame_Exit.SetSize(80,40);
        Endgame_Exit.SetPosition(600,480);
        Endgame_Exit.SetColor({177,235,52});


        ////////////////////////////////////////
        SDL_Texture *Pause = loadTextureFromText("Pause",ColWord,gFont,gRenderer);

        Button Pause_Continue = Button("Continue");
        Pause_Continue.SetSize(80,40);
        Pause_Continue.SetPosition(600,400);
        Pause_Continue.SetColor({177,235,52});


        Button Pause_Exit = Button("Exit");
        Pause_Exit.SetSize(80,40);
        Pause_Exit.SetPosition(600,480);
        Pause_Exit.SetColor({177,235,52});
        ///////////////////////////////////////
        gMusic = Mix_LoadMUS("Amber.mp3");
        if (gMusic== NULL)
        {
            printf("Failed to load music\n");
        }
        bool quit = false;
        while (!quit)
        {
            if (Session == QUIT) {quit = true;}
            while (Session == MENU)
            {
                SDL_Delay(10);
                cout << "-";
                if (Mix_PlayingMusic()==0)
                Mix_PlayMusic(gMusic,-1);
                if( Mix_PausedMusic() == 1 ) Mix_ResumeMusic();
                while (SDL_PollEvent(&gEvent))
                {
                Player.HandleAction(gEvent);
                if (gEvent.type == SDL_QUIT) {Session = QUIT;quit = true;}
                if (gEvent.type == SDL_MOUSEBUTTONDOWN && gEvent.button.button == SDL_BUTTON_LEFT)
                {
                    int x,y;
                    SDL_GetMouseState(&x,&y);
                    if (Menu_Start.InsideButton(x,y)) Session = INGAME;
                    if (Menu_Exit.InsideButton(x,y)) {Session = QUIT;quit = true;}
                }
                }
                SDL_RenderClear(gRenderer);
                gBackground.Render(Image_Background_Default,gRenderer);
                SDL_Rect Temp = {SCREEN_WIDTH/4,SCREEN_HEIGHT/5,2*SCREEN_WIDTH/4,SCREEN_HEIGHT/5};
                Player.Render(Character_Image_Default,gRenderer);
                SDL_RenderCopy(gRenderer,SpaceShooter,NULL,&Temp);
                Menu_Start.Render(gRenderer,gFont);
                Menu_Exit.Render(gRenderer,gFont);
                SDL_RenderPresent(gRenderer);
            }
            while (Session == INGAME)
            {
                SDL_Delay(10);
                cout << "-";
                if (Mix_PlayingMusic()==0)
                Mix_PlayMusic(gMusic,-1);
                if( Mix_PausedMusic() == 1 ) Mix_ResumeMusic();
                while (SDL_PollEvent(&gEvent))
                {
                Player.HandleAction(gEvent);
                if (gEvent.type == SDL_QUIT) {Session = QUIT;quit = true;}
                if (gEvent.type == SDL_KEYDOWN && gEvent.key.keysym.sym == SDLK_ESCAPE) Session = PAUSE;
                }
                HandleOtherMovement(gBackground,Enemy1,Enemy2,Enemy3,Enemy4,Enemy5);
                SDL_RenderClear(gRenderer);
                gBackground.Render(Image_Background_Ingame,gRenderer);
                if (dd[1]) Enemy1.Render(Threat_Image_Green,gRenderer);
                if (dd[2]) Enemy2.Render(Threat_Image_Red,gRenderer);
                if (dd[3]) Enemy3.Render(Threat_Image_Green,gRenderer);
                if (dd[4]) Enemy4.Render(Threat_Image_Red,gRenderer);
                if (dd[5]) Enemy5.Render(Threat_Image_Green,gRenderer);
                Player.Render(Character_Image_Default,gRenderer);
                SDL_RenderPresent(gRenderer);
                if (HandleCollision(Player,Enemy1,Enemy2,Enemy3,Enemy4,Enemy5)) {Session = ENDGAME;Timer = 100;}
            }
            while (Session == PAUSE)
            {
                SDL_Delay(10);
                cout << "-";
                Mix_PauseMusic();
                while (SDL_PollEvent(&gEvent))
                {
                Player.HandleAction(gEvent);
                if (gEvent.type == SDL_QUIT) {Session = QUIT;quit = true;}
                if (gEvent.type == SDL_KEYDOWN && gEvent.key.keysym.sym == SDLK_ESCAPE) Session = INGAME;
                if (gEvent.type == SDL_MOUSEBUTTONDOWN && gEvent.button.button == SDL_BUTTON_LEFT)
                {
                    int x,y;
                    SDL_GetMouseState(&x,&y);
                    if (Pause_Continue.InsideButton(x,y)) Session = INGAME;
                    if (Endgame_Exit.InsideButton(x,y)) {Session = QUIT;quit = true;}
                }
                }
                SDL_Rect Temp = {SCREEN_WIDTH/4,SCREEN_HEIGHT/5,2*SCREEN_WIDTH/4,SCREEN_HEIGHT/5};
                SDL_RenderCopy(gRenderer,Pause,NULL,&Temp);
                Pause_Continue.Render(gRenderer,gFont);
                Pause_Exit.Render(gRenderer,gFont);
                SDL_RenderPresent(gRenderer);

                continue;
            }
            while (Session == ENDGAME)
            {
                SDL_Delay(10);
                cout << "-";
                if (Mix_PlayingMusic()==0)
                Mix_PlayMusic(gMusic,-1);
                if( Mix_PausedMusic() == 1 ) Mix_ResumeMusic();
                while (SDL_PollEvent(&gEvent))
                {
                if (gEvent.type == SDL_QUIT) {Session = QUIT;quit = true;}

                if (Timer==0)
                {
                    if (gEvent.type == SDL_KEYDOWN && gEvent.key.keysym.sym == SDLK_ESCAPE)
                    {
                        dd[1]=0;dd[2]=0;dd[3]=0;dd[4]=0;dd[5]=0;dd[6]=0;
                        Cooldown[1]=20;Cooldown[2]=40;Cooldown[3]=6;
                        Cooldown[4]=7;Cooldown[5]=12;
                        Session = MENU;
                    }
                    if (gEvent.type == SDL_MOUSEBUTTONDOWN && gEvent.button.button == SDL_BUTTON_LEFT)
                {
                    int x,y;
                    SDL_GetMouseState(&x,&y);
                    if (Endgame_Retry.InsideButton(x,y))
                    {
                        dd[1]=0;dd[2]=0;dd[3]=0;dd[4]=0;dd[5]=0;dd[6]=0;
                        Cooldown[1]=20;Cooldown[2]=40;Cooldown[3]=6;
                        Cooldown[4]=7;Cooldown[5]=12;
                        Session = INGAME;

                    }
                    if (Endgame_Exit.InsideButton(x,y)) {Session = QUIT;quit = true;}
                }
                }
                }
                HandleOtherMovement(gBackground,Enemy1,Enemy2,Enemy3,Enemy4,Enemy5);
                SDL_RenderClear(gRenderer);
                gBackground.Render(Image_Background_Ingame,gRenderer);
                if (dd[1]) Enemy1.Render(Threat_Image_Green,gRenderer);
                if (dd[2]) Enemy2.Render(Threat_Image_Red,gRenderer);
                if (dd[3]) Enemy3.Render(Threat_Image_Green,gRenderer);
                if (dd[4]) Enemy4.Render(Threat_Image_Red,gRenderer);
                if (dd[5]) Enemy5.Render(Threat_Image_Green,gRenderer);
                Player.Render(Character_Image_Dead,gRenderer);
                if (Timer == 0)
                {
                    SDL_Texture *YouAreDead = loadTextureFromText("YOU ARE DEAD",ColWord,gFont,gRenderer);
                    SDL_Rect Temp = {SCREEN_WIDTH/4,SCREEN_HEIGHT/5,2*SCREEN_WIDTH/4,SCREEN_HEIGHT/5};
                    SDL_RenderCopy(gRenderer,YouAreDead,NULL,&Temp);
                    Endgame_Retry.Render(gRenderer,gFont);
                    Endgame_Exit.Render(gRenderer,gFont);
                }
                else Timer--;


                SDL_RenderPresent(gRenderer);

            }
        }
    }
    close(&gWindow,&gRenderer,&gFont,&gMusic);
    return 0;
}

