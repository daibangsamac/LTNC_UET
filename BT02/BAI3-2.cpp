#include <iostream>

using namespace std;

int main()
{
    double a,b,c;
    cin >> a >> b >> c;
    if ( a+b <= c || b+c <= a || a+c <=b) return 0;
    cout << a+b+c << endl;
    if (a==b)
    {
        if (b==c) {cout << "tam giac deu";return 0;}
        if ((a*a + b*b) == c*c) {cout << "tam giac vuong can"; return 0;}
        cout << "tam giac can";
        return 0;
    }
    if (b==c)
    {
        if ((b*b+c*c) == a*a) cout << "tam giac vuong can";
        cout << "tam giac can";
        return 0;
    }
    if (a==c)
    {
        if ((a*a+c*c) == b*b) cout << "tam giac vuong can";
        cout << "tam giac can";
        return 0;
    }
    if ((a*a + b*b) == c*c ||(a*a + c*c) == b*b ||(c*c + b*b) == a*a) {cout << "tam giac vuong"; return 0;}
    cout << "tam giac thuong";
    return 0;
}
