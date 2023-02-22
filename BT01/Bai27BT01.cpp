#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n==-1) {cout << "Bye";break;}
        if (n%5) cout << "-1";
        else cout << n/5;
    }
    return 0;
}
