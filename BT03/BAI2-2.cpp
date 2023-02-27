#include <iostream>

using namespace std;
int a[1000006];
int main()
{
    int n,mi,ma,t=0,dem=0;
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    mi=a[1];
    ma=a[1];
    if (a[1]%2) dem++;else t+=a[1];
    for (int i=2;i<=n;i++)
    {
        mi=a[i];
        ma=a[i];
        if (a[i]%2) dem++;else t+=a[1];
    }
    cout << mi << endl;
    cout << ma << endl;
    cout << t << endl;
    cout << dem;
    return 0;
}
