#include <iostream>
#include <algorithm>
using namespace std;
long long t=0,a[1000006];
int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    sort ( a+1,a+1+n );
    for (int i=1;i<n;i++)
        t+= a[i]*(long long)(n-i);
    cout << t;
    return 0;
}
