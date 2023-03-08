#include <iostream>

using namespace std;
string Thu(int Ngay,int Thang,int Nam)
{
    int NgayTrongThang[13];
    NgayTrongThang[1]=30;
    NgayTrongThang[2]=28;
    NgayTrongThang[3]=31;
    NgayTrongThang[4]=30;
    NgayTrongThang[5]=31;
    NgayTrongThang[6]=30;
    NgayTrongThang[7]=31;
    NgayTrongThang[8]=31;
    NgayTrongThang[9]=30;
    NgayTrongThang[10]=31;
    NgayTrongThang[11]=30;
    NgayTrongThang[12]=31;
    // 1/1/1 Thu Bay
    int Ngay_Dif = (Nam-1) * 365 + Nam/4 - Nam/100;
    for (int i=1;i<Thang;i++)
        Ngay_Dif+=NgayTrongThang[i];
    Ngay_Dif+=Ngay;
    Ngay_Dif = Ngay_Dif % 7;
    switch (Ngay_Dif)
    {
    case 1:
        return "Chu Nhat";
        break;
    case 2:
        return "Thu Hai";
        break;
    case 3:
        return "Thu Ba";
        break;
    case 4:
        return "Thu Tu";
        break;
    case 5:
        return "Thu Nam";
        break;
    case 6:
        return "Thu Sau";
        break;
    case 0:
        return "Thu Bay";
        break;
    }
    return "";
}
int main()
{
    int Ngay,Thang,Nam;
    cin >> Ngay >> Thang >> Nam;
    cout << Thu(Ngay,Thang,Nam);
    return 0;
}
