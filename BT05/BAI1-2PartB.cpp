#include <iostream>

using namespace std;
bool majority(bool a,bool b,bool c)
{
    return (bool) ((int) (a+b+c)/2);
}
bool eq(int a[],int b[],const int n)
{
    for (int i=1;i<=n;i++) if (a[i]!=b[i]) return false;
    return true;
}
void Bai1()
{
    cout << "Bai 1:\n";
    cout << "Nhap 3 gia tri 1(true) 0(false):\n";
    char a,b,c;
    cin >> a >> b >> c;
    int a1,b1,c1;
    a1 = a - '0';
    b1 = b - '0';
    c1 = c - '0';
    if (majority(a1,b1,c1)) cout << "true";else cout << "false";
    cout << endl;
}
void Bai2()
{
    int n,a[20],b[20];
    cout << "Bai 2:\n";
    cout << "Nhap n:\n";
    cin >> n;
    cout << "Nhap mang 1 gom " << n << " phan tu:\n";
    for (int i=1;i<=n;i++) cin >> a[i];
    cout << "Nhap mang 2 gom " << n << " phan tu:\n";
    for (int i=1;i<=n;i++) cin >> b[i];
    if (eq(a,b,n)) cout << "true";else cout << "false";
}
int main()
{
    Bai1();
    Bai2();
    return 0;
}
