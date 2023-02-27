#include <iostream>

using namespace std;
int d[4]={0,1,0,-1};
int h[4]={1,0,-1,0};
int a[11][11];
int main()
{
    int x,y,p=0;
    cin >> x >> y;
    int m=1,n=0;
    for (int i=1;i<=x*y;i++)
    {
        int u=m+d[p];
        int v=n+h[p];
        if (u>x||u<1||v>y||v<1||a[u][v]!=0) p++;
        p=p%4;
        u=m+d[p];
        v=n+h[p];
        m=u;
        n=v;
        a[u][v]=i;
    }
    for (int i=1;i<=x;i++){
        for (int j=1;j<=y;j++) cout << a[i][j] << " ";
        cout << endl;
        }
    return 0;
}
