#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int a,b,t,h;
    cin >> a >> b;
    t= a + b;
    h= abs(a-b);
    cout << (t+h)/2;
    return 0;
}
