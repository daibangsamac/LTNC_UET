#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Tong so mon hoc can tinh DTB: ";
    cin >> n;
    double TongDiem=0;
    double TongHeSo=0;
    for (int i=1;i<=n;i++)
    {
        double t,hs;
        cout << "Diem mon hoc " << i << ": ";
        cin >> t;
        while (t<0 || t > 10)
        {
            cout << "Nhap lai diem mon hoc " << i <<" (trong khoang tu 0,0..10,0): ";
            cin >> t;
        }
        cout << "He so mon hoc " << i << ": ";
        cin >> hs;
        while (hs!= (double)1 && hs != (double)1.5 && hs != (double)2 && hs!=(double)2.5 && hs !=(double)3)
        {
            cout << "Nhap lai he so mon hoc " << i <<" (1 1.5 2 2.5 hoac 3): ";
            cin >> hs;
        }
        TongDiem += t*hs;
        TongHeSo += hs;
    }
    cout << "So mon hoc: " << n << "\n";
    cout << "Tong so he so: " << TongHeSo << "\n";
    cout << "Diem trung binh cua " << n << " mon hoc: " << TongDiem/TongHeSo;
    return 0;
}
