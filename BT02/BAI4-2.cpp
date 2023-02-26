#include <iostream>

using namespace std;
long long GCD(long long x,long long y)
{
    while (y!=0)
    {
        x = x%y;
        long long t=y;
        y = x;
        x=t;
    }
    return x;
}
int main()
{
    long long x,y;
    cin >> x >> y;
    cout << x*y*GCD(x,y);
    return 0;
}
