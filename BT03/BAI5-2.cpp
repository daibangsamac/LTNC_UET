#include <iostream>
#include <iomanip>
using namespace std;
double Toan[1003],Ly[1003],Anh[1003],DTB[1003];
int Sinhvien[1003];
int sw(int x,int y)
{
    swap(Sinhvien[x],Sinhvien[y]);
    swap(Toan[x],Toan[y]);
    swap(Ly[x],Ly[y]);
    swap(Anh[x],Anh[y]);
    swap(DTB[x],DTB[y]);
    return 0;
}
int main()
{
    //freopen("test.inp","r",stdin);
    int n=0;
    cout << "Nhap diem so sinh vien theo thu tu Toan, Ly, Anh.\n";
    //cout << "Nhap vao 1 ki tu bat ki khong phai so de dung.\n";
    while (true)
    {

        n++;
        if (!(cin >> Toan[n])) break;
        while (Toan[n]>10||Toan[n]<0)
            {
                cout << "Nhap lai diem Toan sinh vien " << n << ": ";
                cin >> Toan[n];
            }
        cin >> Ly[n];
        while (Ly[n]>10||Ly[n]<0)
            {
                cout << "Nhap lai diem Ly sinh vien " << n << ": ";
                cin >> Ly[n];
            }
        cin >> Anh[n];
        while (Anh[n]>10||Anh[n]<0)
            {
                cout << "Nhap lai diem Anh sinh vien " << n << ": ";
                cin >> Anh[n];
            }
    }
    n--;
    for (int i=1;i<=n;i++)
            {
                Sinhvien[i]=i;
                DTB[i] = (Toan[i] + Ly[i] + Anh[i])/3.0;
            }
    cout << fixed << setprecision(1);
    ///////////////////////////////////////////////
    cout << "Theo diem mon Toan:\n";
    cout << setw(21) << "Toan" << setw(10) << "Ly" << setw(10) << "Anh" << endl;
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (Toan[i]<Toan[j]) sw(i,j);
    for (int i=1;i<=n;i++)
        cout << "Sinh Vien " << Sinhvien[i] << setw(10) << Toan[i] << setw(10) << Ly[i] << setw(10) << Anh[i] <<endl;
    //////////////////////////////////////////////
    cout << "Theo diem mon Ly:\n";
    cout << setw(21) << "Toan" << setw(10) << "Ly" << setw(10) << "Anh" << endl;
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (Ly[i]<Ly[j]) sw(i,j);
    for (int i=1;i<=n;i++)
        cout << "Sinh Vien " << Sinhvien[i] << setw(10) << Toan[i] << setw(10) << Ly[i] << setw(10) << Anh[i] <<endl;
    //////////////////////////////////////////////
    cout << "Theo diem mon Anh:\n";
    cout << setw(21) << "Toan" << setw(10) << "Ly" << setw(10) << "Anh" << endl;
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (Anh[i]<Anh[j]) sw(i,j);
    for (int i=1;i<=n;i++)
        cout << "Sinh Vien " << Sinhvien[i] << setw(10) << Toan[i] << setw(10) << Ly[i] << setw(10) << Anh[i] <<endl;
    //////////////////////////////////////////////
    cout << "Theo diem trung binh:\n";
    cout << setw(21) << "DTB" << setw(10) <<"Toan" << setw(10) << "Ly" << setw(10) << "Anh" << endl;
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (DTB[i]<DTB[j]) sw(i,j);
    for (int i=1;i<=n;i++)
        cout << "Sinh Vien " << Sinhvien[i] << setw(10) << DTB[i] << setw(10) << Toan[i] << setw(10) << Ly[i] << setw(10) << Anh[i] <<endl;
    return 0;
}
