#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long p=sqrt(n);
    if (p*p==n) cout <<"yes";
    else cout << "no";
    return 0;
}
