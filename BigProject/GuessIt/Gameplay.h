#include <time.h>
#include <cstdlib>

int ChooseNumber()
{
    srand(time(NULL));
    int t = (rand() * 123 + 192 * rand()) % 100;
    return t;
}

int getGuessedNumber (string s)
{
    if (s[0])
}
