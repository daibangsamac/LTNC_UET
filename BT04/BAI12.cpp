#include <iostream>
#include <cmath>
using namespace std;
int n,a[1000006];
void snt(int n)
{
    for (int i=2;i<=sqrt(n);i++)
        if (a[i]==0)
        for (int j=2;j<=n/i;j++) a[i*j]=1;
}
int main()
{
    cin >> n;
    snt(n);
    for (int i=2;i<=n;i++) if (a[i]==0) cout << i << " ";
    return 0;
}
