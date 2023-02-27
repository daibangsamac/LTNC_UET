#include <iostream>

using namespace std;
int f[100005];
string ITS(int x)
{
    string r="";
    while (x > 0)
    {
        int p = x%10;
        x=x/10;
        char c = p + '0';
        r = c + r;
    }
    return r;
}
/*bool*/ int check(int x)
{
    //if (f[x]==1) return true;
    //if (f[x]==-1) return false;
    string r = ITS(x);
    int n = r.length();
    for (int i=0;i<n/2;i++)
        if (r[i]!=r[n-1-i]) return 0; //false;
    f[x] = 1;
    return 0; //true;
}
int Pre()
{
    for (int i=0;i<=100000;i++)
    {
        check(i);
        f[i] += f[i-1];
    }
    return 0;
}
int main()
{
    Pre();
    int t,a,b;
    cin >> t;
    while (t > 0)
    {
        t--;
        cin >> a >> b;
        cout << f[b]-f[a-1] << endl;
    }
    return 0;
}
