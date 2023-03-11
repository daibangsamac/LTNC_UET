#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
    srand(time(0));
    int n,p;
    cin >> n;
    p=rand()%n;
    cout << p;
    return 0;
}
