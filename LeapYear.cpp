#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    if (x%4 !=0 || x %100 ==0) cout << "false";
    else cout << "true";
    return 0;
}
