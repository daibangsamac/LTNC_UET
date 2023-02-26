#include <iostream>

using namespace std;

int main()
{
    int x,y=-1;
    while (true)
    {
        cin >> x;
        if (x<0) {cout << x;return 0;}
        if (x==y) continue;
        cout << x;
        y=x;
    }
    return 0;
}
