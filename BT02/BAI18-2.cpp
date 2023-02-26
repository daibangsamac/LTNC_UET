#include <iostream>

using namespace std;

int main()
{
    int i=0;
    double tb=0;
    while (true)
    {
        i++;
        double t;
        cout << "Diem mon hoc " << i << ": ";
        cin >> t;
        while (t > 10)
        {
            cout << "Nhap lai diem mon hoc " << i << " (trong khoang tu 0..10): ";
            cin >> t;
        }
        if (t<0)
        {
            i--;
            cout << "So mon hoc: " << i << endl;
            cout << "Diem trung binh cua " << i << " mon hoc: " << tb/(double)i;
            return 0;
        }
        tb += t;
    }
    return 0;
}
