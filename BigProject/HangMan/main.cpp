#include <bits/stdc++.h>
#include <Game.h>
using namespace std;


int main(int argc, char* argv[])
{
    if (!Init())
    {
        printf("Unable to initialize\n");
    }
    else
    {
        loadMedia();
    }
    close();
    return 0;
}
