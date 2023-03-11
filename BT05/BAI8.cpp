#include <iostream>
#include <cmath>
using namespace std;
int rnd1(double x)
{
    int u=ceil(x);
    int v=floor(x);
    if ((double)(x-v) > (double) (u-x)) return u;
        else return v;
}
int rnd2(double x)
{
    int q=(int) x;
    double p=x-(double)q;
    if (p>0.5) return q+1;
    return q;
}
int main()
{
    double n;
    cin >> n;
    cout << rnd1(n) << endl;
    cout << rnd2(n);
    return 0;
}
