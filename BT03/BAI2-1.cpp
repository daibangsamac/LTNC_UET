#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n=s.length();
    for (int i=0;i<n/2;i++)
    if (s[i]!=s[n-1-i]) {cout << "NO";return 0;}
    cout << "YES";
    return 0;
}
