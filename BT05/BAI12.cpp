#include <iostream>

using namespace std;
int kiemTra(int k, int n)
{
    if (k<0||k>n||n<1||n>20) return 0;
    return 1;
}
int toHop(int k, int n)
{
    int t=1,q=1;
    for (int i=1;i<=k;i++)
    {
        t=t*(n-i+1);
        q=q*i;
    }
    return t/q;
}
void nhapKN(int k[],int n[],int *sophantu)
{
    while (true)
    {int x,y;
    cin >> x >> y;
    if (x==-1&&y==-1) return ;
    if (kiemTra(x,y)==0) continue;
    (*sophantu)++;
    k[*sophantu]=x;
    n[*sophantu]=y;
    }
}
int main()
{
    //freopen("test.inp","r",stdin);
    int n=0;
    int a[21],b[21];
    nhapKN(a,b,&n);
    for (int i=1;i<=n;i++)
    cout << toHop(a[i],b[i]) << endl;
    return 0;
}
