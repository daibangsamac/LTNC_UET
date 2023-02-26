#include <iostream>
#include <cmath>
using namespace std;
int a[1000004];
void snt()
{
    for (int i=2;i<=1000;i++)
        if (a[i]==0)
        for (int j=2;j<=1000000/i;j++) a[i*j]=1;
}
bool prime (int x)
{
    if (a[x]==0) return true;
    return false;
}
bool cp (int x)
{
    int tmp=sqrt(x);
    if (tmp*tmp==x) return true;
    return false;
}
bool tp (int x)
{
    int q = pow (x,1.0/3.0);
    if (q*q*q==x) return true;
    return false;
}
bool check (int x)
{
    if (prime(x)) return true;
    if (cp(x)) return true;
    if (tp(x)) return true;
    return false;
}
int main()
{
    int n;
    snt();
    cin >> n;
    for (int i=2;i<=n;i++)
        if (check(i)) cout << i << " ";
    return 0;
}
