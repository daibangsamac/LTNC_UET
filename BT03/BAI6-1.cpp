#include <iostream>

using namespace std;
int a[20][20];
int main()
{
    int n;
    cin >> n;
    int x=1;
    int y=n/2+1;
    a[x][y]=1;
    for (int i=2;i<=n*n;i++)
    {
        int u=x-1;
        int v=y+1;
        if (u==0) u=n;
        if (v>n) v=1;
        if (a[u][v]!=0)
        {
            u=x+1;
            v=y;
            if (u>n) u=1;
        }
        a[u][v]=i;
        x=u;
        y=v;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++) cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
