#include <iostream>

using namespace std;
string TenToBinary(string s)
{
    int q=0;
    string r="";
    int n=s.length();
    for (int i=0;i<n;i++) q = q*10 + (s[i]-'0');
    if (q==0) return "0";
    while (q>0)
    {
        char c=q%2 + '0';
        q=q/2;
        r = c +r;
    }
    return r;
}
int BinaryToTen(string s)
{
    int n=s.length();
    int t=(1<<n)-1;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='1') continue;
        t = t - ((1<<(n-i-1)));
    }
    return t;
}
int main()
{
    while (true)
    {
        int q;
        cout << "Choose form:";
        cin >> q;
        cout << "Type Number:";
        string s;
        cin >> s;
        if (q==10) cout << TenToBinary(s) << endl;
        if (q==2) cout << BinaryToTen(s) << endl;
    }
    return 0;
}
