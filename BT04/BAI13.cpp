#include <iostream>

using namespace std;
int t,n,a[100005];
int main()
{
    cin >> t;
    while (t>0)
    {
        bool p=false;
        t--;
        cin >> n;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
            a[i]=a[i-1]+a[i];
        }
        for (int i=1;i<=n;i++)
        if ((a[i-1]-a[0])==(a[n]-a[i])) {p=true;break;}
        if (p) cout << "YES\n";else cout << "NO\n";
    }
    return 0;
}
