#include <iostream>

using namespace std;
bool cot[100],DuongcheoDB[202],DuongcheoDN[202];
int dd[100][100],n;
bool q=false;
bool Control(int x,int i)
{
    if (cot[i]==1) return true;
    int u=x+i+n;
    int v=i-x+n;
    if (DuongcheoDB[v]==1) return true;
    if (DuongcheoDN[u]==1) return true;
    return false;
}
void upd(int x,int i)
{
    int u=x+i+n;
    int v=i-x+n;
    cot[i]=1;
    DuongcheoDB[v]=1;
    DuongcheoDN[u]=1;
    return;
}
void degrade(int x,int i)
{
    int u=x+i+n;
    int v=i-x+n;
    cot[i]=0;
    DuongcheoDB[v]=0;
    DuongcheoDN[u]=0;
    return;
}
void Print()
{
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) if (dd[i][j]) cout << "*";else cout <<".";
    cout <<endl;
    }
    return;
}
void xep(int x)
{
    if (q) return;
    for (int i=1;i<=n;i++)
    {
        if (Control(x,i)) continue;
        dd[x][i]=1;
        upd(x,i);
        if (x==n) {Print();q=true;return;}
        xep(x+1);
        dd[x][i]=0;
        degrade(x,i);
    }
}
int main()
{
    cin >> n;
    xep(1);
    return 0;
}
