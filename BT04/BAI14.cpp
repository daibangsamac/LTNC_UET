#include <iostream>

using namespace std;
int n,a[102];
int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int j=1;j<=n+1;j++)
    {
        int x;
        cin >> x;
        a[x]--;
        if (a[x]<0) {cout << x;return 0;}
    }
    return 0;
}
