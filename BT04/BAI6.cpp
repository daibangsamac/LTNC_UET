#include <iostream>

using namespace std;
int n,a[1003];
int main()
{
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            for (int k=1;k<=n;k++)
    {
        if (a[i]+a[j]+a[k]==0) {cout << a[i] << " " << a[j] << " " << a[k];return 0;}
    }
    return 0;
}
