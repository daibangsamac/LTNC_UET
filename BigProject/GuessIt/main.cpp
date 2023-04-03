#include <time.h>
#include <cstdlib>
#include <Renderer.h>
int ChooseNumber()
{
    srand(time(NULL));
    int t = (rand() * 123 + 192 * rand()) % 100;
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

            }
        }
    }
    return 0;
}
