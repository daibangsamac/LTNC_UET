#include <iostream>

using namespace std;
int dd[1000006];
int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        if (dd[x]) {cout << "YES"; return 0;}
        dd[x]=1;
    }
    cout << "NO";
    return 0;
}
