#include <iostream>
#include <algorithm>
using namespace std;
int Nam[10005],Nu[10005];
int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> Nam[i] >> Nu[i];
    sort (Nam+1,Nam+1+n);
    sort (Nu+1,Nu+1+n);
    for (int i=1;i<=n;i++) if (Nam[i]<=Nu[i]) {cout << "NO";return 0;}
    cout << "YES";
    return 0;
}
