#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    long long r=0;
    int n=s.length();
    for (int i=0;i<n;i++)
    {
        int tmp=s[i]-'0';
        r+=tmp;
    }
    cout << r;
    return 0;
}
