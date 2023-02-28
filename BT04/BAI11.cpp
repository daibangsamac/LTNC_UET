#include <iostream>

using namespace std;
string s[101];
int n;
bool check(int i,int j)
{
    int p1=s[i].length();
    int p2=s[j].length();
    int q=p2-1;
    if (p1!=p2) return false;
    for (int k=0;k<p1;k++)
    {
        if (s[i][k]!=s[j][q]) return false;
        q--;
    }
    return true;
}
int print(int i,int j)
{
    int p1=s[i].length();
    cout << p1 << " " << s[i][p1/2];
    return 0;
}
int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> s[i];
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
        if (check(i,j)) {print(i,j);return 0;}
    return 0;
}
