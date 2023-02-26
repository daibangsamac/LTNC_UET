#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "Fahrenheit\tCelsius\t\tAbsolute Value\n";
    double x;
    while (cin >> x)
    {
        double C= ((x-32) * 5) / 9;
        double K= C + 273.15;
        cout << fixed << setprecision(2);
        cout << x << "\t\t" << C << "\t\t" << K << endl;
    }
    return 0;
}
