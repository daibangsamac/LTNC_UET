#include <iostream>

using namespace std;
int d[8]={-1,0,1,-1,1,-1,0,1};
int h[8]={-1,-1,-1,0,0,1,1,1};
char r[10][10],a[10][10];
int main()
{
    int m,n;
    cin >> m >> n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) cin >> a[i][j];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        if (a[i][j]!='*')
    {
        int p=0;
        for (int k=0;k<8;k++)
        {
            int u = i + d[k];
            int v = j + h[k];
            if (a[u][v]== '*') p++;
        }
        char c= p + '0';
        r[i][j]=c;
    }
    else r[i][j]='*';
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++) cout << r[i][j]<<" ";
    cout << endl;
    }
    return 0;
}
