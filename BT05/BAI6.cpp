#include <iostream>

using namespace std;
int GCD(int x,int y)
{
    if (y==0) return x;
    return GCD(y,x%y);
}
int main()
{
    int a,b;
    cin >> a >> b;
    int d=GCD(a,b);
    if (d==1) cout << "Nguyen to cung nhau";
    else cout << "Khong nguyen to cung nhau";
    return 0;
}
