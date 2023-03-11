#include <iostream>
#include <cmath>
using namespace std;
int a[1000006];
void snt(int n)
{
    a[1]=1;
    for (int i=2;i<=sqrt(n);i++)
        if (a[i]==0) for (int j=2;j<=n/i;j++) a[i*j]=1;

}
bool Is_prime(int x)
{
    if (a[x]==0) return true;
    return false;
}
int main()
{
    int n;
    cin >> n;
    snt(n);
    for (int i=1;i<=n;i++)
        if (Is_prime(i)) cout << i << " ";
    return 0;
}
