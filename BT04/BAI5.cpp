#include <iostream>
#include <algorithm>
using namespace std;
int n,a[10003];
int main()
{
    /*cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
        if (a[i]+a[j]==0) {cout << a[i] << " " << a[j];return 0;}*/
    cin >> n;
    int p=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (a[i]==0) p++;
    }
    if (p>1) {cout << "0 0";return 0;}
    sort (a+1,a+1+n);
    for (int i=1;i<=n;i++)
        if (a[i]!=0)
    {
        int j=lower_bound(a+1,a+1+n,-a[i])-a;
        if (a[i]==-a[j]) {cout << a[i] << " " << a[j];return 0;}
    }
    return 0;
}
