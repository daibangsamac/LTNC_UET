#include <time.h>
#include <cstdlib>
#include <Renderer.h>
#include <windows.h>
#include <iostream>
using namespace std;
int ChooseNumber()
{
    srand(time(NULL));
    int t = (rand() * 123 + 192 * rand()) % 100 + 1;
    return t;
}

int main(int atgc, char*argv[])
{
    if (!Init())
    {
        printf("Failed to initialized\n");
    }
    else
    {
        if (!loadMedia())
        {
            printf("Failed to load media\n");
        }
        else
        {

            bool quit = false;
            SDL_Event e;
            while (!quit)
            {
                SDL_RenderClear( gRenderer );
                SDL_RenderCopy( gRenderer, gTexture[Image_Default], NULL, NULL );
                SDL_RenderPresent(gRenderer);
                bool Victory = false;
                int ChosenNumber = ChooseNumber();
                //cout << "Chosen Number: " << ChosenNumber << endl;
                while (!Victory && !quit)
                    {
                        bool Guessed = false;
                        int ImageShown = Image_Default;
                        int GuessedNumber = 0;
                        while (!Guessed && !quit)
                                {
                                    SDL_RenderClear( gRenderer );
                                    SDL_RenderCopy( gRenderer, gTexture[ImageShown], NULL, NULL );
                                    SDL_RenderPresent(gRenderer);
                                    while (SDL_PollEvent(&e)!=0)
                                    {
                                        if( e.type == SDL_QUIT )
                                            {
                                                quit = true;
                                            }
                                        if (e.type == SDL_KEYDOWN)
                                            {
                                                switch (e.key.keysym.sym)
                                                {
                                                case SDLK_ESCAPE:
                                                    quit = true;
                                                    break;
                                                case SDLK_RETURN: case SDLK_KP_ENTER:
                                                    Guessed = true;
                                                    break;
                                                case SDLK_BACKSPACE:
                                                    GuessedNumber = GuessedNumber / 10;
                                                    break;
                                                case SDLK_0: case SDLK_KP_0:
                                                    GuessedNumber = GuessedNumber * 10;
                                                    break;
                                                case SDLK_1: case SDLK_KP_1:
                                                    GuessedNumber = GuessedNumber * 10 + 1;
                                                    break;
                                                case SDLK_2: case SDLK_KP_2:
                                                    GuessedNumber = GuessedNumber * 10 + 2;
                                                    break;
                                                case SDLK_3: case SDLK_KP_3:
                                                    GuessedNumber = GuessedNumber * 10 +3;
                                                    break;
                                                case SDLK_4: case SDLK_KP_4:
                                                    GuessedNumber = GuessedNumber * 10 + 4;
                                                    break;
                                                case SDLK_5: case SDLK_KP_5:
                                                    GuessedNumber = GuessedNumber * 10 + 5;
                                                    break;
                                                case SDLK_6: case SDLK_KP_6:
                                                    GuessedNumber = GuessedNumber * 10 + 6;
                                                    break;
                                                case SDLK_7: case SDLK_KP_7:
                                                    GuessedNumber = GuessedNumber * 10 + 7;
                                                    break;
                                                case SDLK_8: case SDLK_KP_8:
                                                    GuessedNumber = GuessedNumber * 10 + 8;
                                                    break;
                                                case SDLK_9: case SDLK_KP_9:
                                                    GuessedNumber = GuessedNumber * 10 +9;
                                                    break;
                                                }
                                            }
                                    }
                                if (!Guessed) continue;
                                //cout << "Guessed Number: " << GuessedNumber << endl;
                                if (GuessedNumber > ChosenNumber) ImageShown = Image_Lower;
                                if (GuessedNumber < ChosenNumber) ImageShown = Image_Higher;
                                if (GuessedNumber <1||GuessedNumber>100) ImageShown = Image_WrongInput;
                                if (GuessedNumber == ChosenNumber) {Victory = true;ImageShown = Image_Victory;}
                                }
                        SDL_RenderClear( gRenderer );
                        SDL_RenderCopy( gRenderer, gTexture[ImageShown], NULL, NULL );
                        SDL_RenderPresent(gRenderer);
                        bool NextGuess = false;
                        while (!NextGuess && !quit && !Victory)
                        {
                            while (SDL_PollEvent(&e)!=0)
                            {
                                if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE )) {quit = true;}
                            if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_KEYDOWN) NextGuess = true;
                            }
                        }
                    }
                bool Nextgame = false;
                while (!Nextgame && !quit)
                {
                    while (SDL_PollEvent(&e)!=0)
                        {
                            if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE )) {quit = true;}
                            if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_KEYDOWN) Nextgame = true;
                        }
                }
            }
        }
    }
    close();
    return 0;
}
