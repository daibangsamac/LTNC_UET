#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a,b,c;
    cin >> a >> b >> c;
    double d = b*b -4*a*c;
    if (d==0) { cout << -b/(2*a);return 0;}
    if (d>0) { cout << (-b-sqrt(d))/(2*a) << " " << (-b+sqrt(d))/(2*a); return 0;}
    if (d<0)
        {
            //cout << fixed << setprecision(2);
             cout << -b/(2*a) << " + i" << sqrt(-d)/(2*a) << "\n" << -b/(2*a) << " - i" << sqrt(-d)/(2*a);
    return 0;
    }
    return 0;
}
