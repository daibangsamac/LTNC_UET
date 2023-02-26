#include <iostream>

using namespace std;

int main()
{
    double a1,a2,b1,b2,c1,c2;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    if (a1/a2 == b1/b2)
    {
        if (a1/a2 == c1/c2) {cout << "vo so nghiem"; return 0;}
        cout << "vo nghiem";
        return 0;
    }
    cout << "x = " << ( (c1*b2) - (b1*c2) )/ ( (a1*b2) - (a2*b1) ) << endl;
    cout << "y = " << ( (c2*a1) - (a1*c1) )/ ( (a1*b2) - (a2*b1) );
    return 0;
}
