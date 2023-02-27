#include <iostream>
#include <cmath>
using namespace std;
double t,a[1000006];
int main()
{
    double u=0;
    int n=1;
    while (cin >> a[n])
        {
            u+=a[n];
            n++;
        }
    u=u/(double)n;
    double v=0;
    for (int i=1;i<=n;i++)
        v+=(a[i]-u)*(a[i]-u);
    v=v/(double)n;
    cout << u << " " << v;
    return 0;
}
