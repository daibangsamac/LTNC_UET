#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int Board[12][12],dd[12][12];
int d[8]={-1,-1,-1,0,0,1,1,1};
int h[8]={-1,0,1,-1,1,-1,0,1};
void CreateBoard(int m,int n,int k);
void Print_Ingame(int m,int n,int k);
void Print_After(int m, int n,int k,int Status);
bool ins(int x,int y,int m,int n);
void CreateBoard(int m,int n,int k)
{
    srand(time(0));
    while (k>0)
    {
        int u=rand()%m +1;
        int v=rand()%n +1;
        if (Board[u][v]!=0) continue;
        Board[u][v]=-1;
        k--;
    }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if (Board[i][j]==0)
        for (int k=0;k<8;k++)
        {
            int u=i+d[k];
            int v=j+h[k];
            if (Board[u][v]==-1)
            Board[i][j]++;
        }
}
void Print_Ingame(int m,int n,int k)
{
    system("cls");
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
            if (dd[i][j]==0)
                cout << "o";
            else cout << Board[i][j];
        cout << "\n";
    }
}
void Print_After(int m,int n,int k, int Status)
{
    system("cls");
    if (Status == 1) cout << "Congratulations\n";
    else cout << "You are dead\n";
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
            if (Board[i][j]==-1) cout << "*";
            else cout << Board[i][j];
        cout << "\n";
    }
}
bool ins(int x,int y,int m,int n)
{
    if (x<1||x>m||y<1||y>n) return false;
    return true;
}
int main()
{
    int m,n,k;
    cin >> m >> n >> k;
    CreateBoard(m,n,k);
    int GameOver = 0;
    int GuessedTimes=0;
    while (GameOver==0)
    {
        GuessedTimes++;
        Print_Ingame(m,n,k);
        cout << "Nhap toa do:";
        int x,y;
        cin >> x >> y;
        while (!ins(x,y,m,n) || dd[x][y]!=0)
        {
            cout << "Nhap lai toa do:";
            cin >> x >> y;
        }
        if (Board[x][y]==-1) {GameOver=-1;continue;}
        else dd[x][y]=1;
        if (GuessedTimes==m*n-k) GameOver=1;
    }
    Print_After(m,n,k,GameOver);
}
