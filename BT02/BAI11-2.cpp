#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double mi, ma, step;
    cin >> mi >> ma >> step;
    cout << "Fahrenheit\tCelsius\t\tAbsolute Value\n";
    double x;
    while (mi <= ma)
    {
        x = mi;
        mi += step;
        double C= ((x-32) * 5) / 9;
        double K= C + 273.15;
        cout << fixed << setprecision(2);
        cout << x << "\t\t" << C << "\t\t" << K << endl;
    }
    return 0;
}
