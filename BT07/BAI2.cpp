#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int a[7]={0,0,9,-12,1,-2};
int b[5]={0,3,1,-6};
void chay (int &vtri_tho,int &vtri_rua)
{
    int i=(rand()*91 + 127*rand()) % 10;
    int j=(rand()*256 + 378*rand()) % 10;
    int u,v;
    if (i<5) u=1;
    if (i>=5&&i<8) u=2;
    if (i>7) u=3;
    if (j<2) v=1;
    if (j>1&&j<4) v=2;
    if (j==4) v=3;
    if (j>4&&j<8) v=4;
    if (j>7) v=5;
    vtri_tho += a[v];
    vtri_rua += b[u];
    if (vtri_tho<0) vtri_tho=0;
    if (vtri_tho>70) vtri_tho=70;
    if (vtri_rua<0) vtri_rua=0;
    if (vtri_rua>70) vtri_rua=70;
    switch (u)
    {
    case 1:
        cout << "Rua tien dai. Vi tri rua: " << vtri_rua<<endl;
        break;
    case 2:
        cout << "Rua tien ngan. Vi tri rua: " << vtri_rua<<endl;
        break;
    case 3:
        cout << "Rua truot. Vi tri rua: " << vtri_rua<<endl;
        break;
    }
    switch (v)
    {
    case 1:
        cout << "Tho ngu. Vi tri tho: " << vtri_tho<<endl;
        break;
    case 2:
        cout << "Tho tien dai. Vi tri tho: " << vtri_tho<<endl;
        break;
    case 3:
        cout << "Tho truot dai. Vi tri tho: " << vtri_tho<<endl;
        break;
    case 4:
        cout << "Tho tien ngan. Vi tri tho: " << vtri_tho<<endl;
        break;
    case 5:
        cout << "Tho truot ngan. Vi tri tho: " << vtri_tho<<endl;
        break;
    }
}
void Race()
{
    cout << "Bat dau\n";
    int tho=0,rua=0,i=1;
    while (tho<70 && rua<70)
        {
            cout << "Luot " << i << ":" << endl;
            i++;
            chay(tho,rua);
        }
    cout << "Ket thuc\n";
    if (tho==rua) {cout << "Hoa";return;}
    if (tho==70) cout << "Nguoi chien thang la tho";
    if (rua==70) cout << "Nguoi chien thang la rua";
}
int main()
{
    srand(time(NULL));
    Race();
    return 0;
}
