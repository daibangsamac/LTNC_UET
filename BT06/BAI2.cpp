#include <iostream>

using namespace std;
int dd1[30],dd2[30];
void Print(int k)
{
    for (int i=1;i<=k;i++)
    {
        char c=dd2[i]-1 + 'a';
        cout << c;
    }
    cout << endl;
}
void sinh(int x,int n,int k)
{
    for (int i=1;i<=n;i++)
    {
        if (dd1[i]==1) continue;
        dd2[x]=i;
        dd1[i]=1;
        if (x==k) Print(k);
        else sinh(x+1,n,k);
        //dd2[x]=0;
        dd1[i]=0;
    }
}
int main()
{
    int n,k;
    cin >> n >> k;
    sinh(1,n,k);
    return 0;
}
