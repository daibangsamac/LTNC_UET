#include <iostream>

using namespace std;
bool Board[10001][10001];
int x[10001],y[10001];
int a[10001];
bool ins(int x,int y,int &n)
{
    if (x>n||y>n||x<0||y<0) return false;
    return true;
}
int Cach1(int &n)
{
    for (int i=1;i<=n;i++)
        {
            int x,y;
            cin >> x >> y;
            Board[x][y] = true;
        }
    /*for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++)
        if (Board[i][j]) cout << "*"; else cout <<".";
        cout << endl;} */
    //////////////////////////////////////// //Cot
    for (int i=0;i<=n;i++)
    {
        int dem=0;
        for (int j=0;j<=n;j++)
            if (Board[i][j]) dem++;
        if (dem>1) {cout << "yes";return 0;}
    }
    /////////////////////////////////////// // Hang
    for (int j=0;j<=n;j++)
    {
        int dem=0;
        for (int i=0;i<=n;i++)
            if (Board[i][j]) dem++;
        if (dem>1) {cout << "yes";return 0;}
    }
    ////////////////////////////////////////
    for (int j=0;j<=n;j++)
        {
            int i=0;
            int dem=0;
            if (Board[i][j]) dem++;
            int u=i+1;
            int v=j+1;
            while (ins(u,v,n))
            {
                if (Board[u][v]) dem++;
                u++;
                v++;
            }
            if (dem>1) {cout << "yes";return 0;}
            ////////////////////////////////
            dem=0;
            if (Board[i][j]) dem++;
            u=i+1;
            v=j-1;
            while (ins(u,v,n))
            {
                if (Board[u][v]) dem++;
                u++;
                v--;
            }
            if (dem>1) {cout << "yes";return 0;}
        }
    ////////////////////////////////////////
    for (int j=0;j<=n;j++)
        {
            int i=n;
            int dem=0;
            if (Board[i][j]) dem++;
            int u=i-1;
            int v=j+1;
            while (ins(u,v,n))
            {
                if (Board[u][v]) dem++;
                u--;
                v++;
            }
            if (dem>1) {cout << "yes";return 0;}
            ///////////////////////////////////////
            dem=0;
            if (Board[i][j]) dem++;
            u=i-1;
            v=j-1;
            while (ins(u,v,n))
            {
                if (Board[u][v]) dem++;
                u--;
                v--;
            }
            if (dem>1) {cout << "yes";return 0;}
        }
    /////////////////////////////////////////
    cout << "no";
    return 0;
}
int GCD(int x,int y)
{
    if (y==0) return x;
    while (y!=0)
    {
        x = x % y;
        int t=x;
        x=y;
        y=t;
    }
    return x;
}
bool Fight(int i,int j)
{
    int u = x[j]-x[i];
    int v = y[j]-y[i];
    int UCLN=GCD(abs(u),abs(v));
    u=u/UCLN;
    v=v/UCLN;
    if (u==0)
        if (v==1||v==-1||v==0) return true;
    if (u==1)
        if (v==1||v==-1||v==0) return true;
    return false;
}
int Cach2(int &n)
{

    for (int i=1;i<=n;i++)
        cin >> x[i] >> y[i];
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
    if (Fight(i,j)) {cout << "yes";return 0;}
    cout << "no";
    return 0;
}
int Cach3(int &n)
{
    for (int i=1;i<=n;i++)
        {
            int x,y;
            cin >> x >> y;
            if (a[x]!=0&&a[x]==y) {cout << "yes";return 0;}
            a[x]=y;
        }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++) if (a[i]==a[j]) {cout << "yes";return 0;}
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            int u=j-i;
            int v=a[j]-a[i];
            int UCLN=GCD(abs(u),abs(v));
            u=u/UCLN;
            v=v/UCLN;
            if (u==0)
                if (v==1||v==-1||v==0) {cout << "yes";return 0;}
            if (u==1)
                if (v==1||v==-1||v==0) {cout << "yes";return 0;}
        }
    }
    cout << "no";
    return 0;
}
int main()
{
    //freopen("test.inp","r",stdin);
    int n;
    cin >> n;
    //Cach1(n);
    //Cach2(n);
    Cach3(n);
    return 0;
}
