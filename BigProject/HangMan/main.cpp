#include <bits/stdc++.h>
#include <Game.h>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <string.h>
using namespace std;
std :: string Words[11] = {"NO","YES","QUEUE","LOSER","LOVE","HATE","EAT","TIME","WINNER","FRANKENSTEIN"};
int dd[30];
std :: string chooseWord()
{
    int n = (rand() * 123 + rand()*987) % 10;
    return Words[n];
}
std :: string chosenWord = "";
void NewGame()
{
    for (int i=0;i<=(int)('z'-'a');i++) dd[i]=0;
    chosenWord = chooseWord();
}
int main(int argc, char* argv[])
{
    srand(time(NULL));
    if (!Init())
    {
        printf("Unable to initialize\n");
    }
    else
    {
        if (!loadMedia())
        {
            printf("Unable to load media\n");
        }
        else
        {
            gBackground.Show(gBackground.Image_Default);
            bool quit = false;
            SDL_Event e;
            while (!quit)
            {
                bool Endgame = false;
                int CountWrongAnswer = 0;
                NewGame();
                while (!Endgame)
                    {
                        int ImageShow = gGallow.Image_Default;
                        if (CountWrongAnswer == 7)
                            {Endgame = true;}
                        while (SDL_PollEvent(&e))
                        {
                        if (e.type == SDL_QUIT)
                        {
                        quit = true;
                        Endgame = true;
                        }
                            if (e.type == SDL_KEYDOWN)
                            if (e.type == SDLK_ESCAPE)
                            {
                                quit = true;
                                Endgame = true;
                            }
                            else
                            {
                                char c = e.key.keysym.sym;
                                int p = c - 'a';
                                if (dd[p] == 1) CountWrongAnswer++;
                                else
                                {
                                    dd[p] = 1;
                                    bool Exist = false;
                                    int n = chosenWord.length();
                                    for (int i=0;i<n;i++)
                                    {
                                        int c2 = chosenWord[i];
                                        int p2 = c2 - 'A';
                                        if (p2 == p) {Exist = true;break;}
                                    }
                                    if (!Exist) CountWrongAnswer++;
                                }
                            }
                        }
                        ////////////////////////////Show Image
                        std :: string ShowWord = "";
                        int n = chosenWord.length();
                        bool win = true;
                        for (int i=0;i<n;i++)
                        {
                            char c = chosenWord[i];
                            int p = c - 'A';
                            if (dd[p] == 1) ShowWord = ShowWord + c;
                            else
                            {
                                win = false;
                                ShowWord = ShowWord + "*";
                            }
                        }
                        cout << ShowWord  << endl;
                        if (CountWrongAnswer == 0) gGallow.Show(gGallow.Image_Default);
                        else
                        {
                            gBody.Show(CountWrongAnswer);
                        }
                        if (win) Endgame = true;
                        if (CountWrongAnswer == 7) gBody.Show(gBody.Image_Default);
                        SDL_Delay(100);
                    }
            }
        }
    }
    close();
    return 0;
}
