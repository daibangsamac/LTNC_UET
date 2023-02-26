#include <iostream>
#include <cmath>
using namespace std;
long long pw (long long x, long long y)
{
    if (y==0) return 1;
    if (y==1) return x;
    long long tmp = pw(x,y/2);
    return tmp * tmp * pw(x,y%2);
}
int main()
{
    long long x,y;
    cin >> x >> y;
    long long r=pw(x,y);
    cout << r <<"\n";
    r=pow(x,y);
    cout << r;
    return 0;
}
