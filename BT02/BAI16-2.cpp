#include <iostream>

using namespace std;

int main()
{
    while (true)
    {
        cout << "Nhap vao mot so trong khoang 0..9: ";
        string s;
        cin >> s;
        int n=s.length();
        if (n > 1) break;
        if (s[0] > '9' || s[0] < '0') break;
        switch ((int) (s[0]-'0'))
        {
        case 0:
            cout << "Vua nhap chu so khong\n";
            break;
        case 1:
            cout << "Vua nhap chu so mot\n";
            break;
        case 2:
            cout << "Vua nhap chu so hai\n";
            break;
        case 3:
            cout << "Vua nhap chu so ba\n";
            break;
        case 4:
            cout << "Vua nhap chu so bon\n";
            break;
        case 5:
            cout << "Vua nhap chu so nam\n";
            break;
        case 6:
            cout << "Vua nhap chu so sau\n";
            break;
        case 7:
            cout << "Vua nhap chu so bay\n";
            break;
        case 8:
            cout << "Vua nhap chu so tam\n";
            break;
        case 9:
            cout << "Vua nhap chu so chin\n";
            break;

        }
    }
    return 0;
}
