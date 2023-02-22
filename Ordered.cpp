#include <iostream>

using namespace std;

int main()
{
    int x,y,z;
    bool b=true;
    cin >> x >> y >> z;
    if ( x <=y && y>=z) b=false;
    if ( x >=y && y<=z) b=false;
    cout << b;
    return 0;
}
