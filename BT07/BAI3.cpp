#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int dd[4]={0,0,0,0};
string inQuanBai(int khoa);
bool uuTienHon(int khoa1, int khoa2);
void traoBai(int *boBai);
void chiaBai(int *boBai, int **boBaiNguoiChoi);
void inBoBaiNguoiChoi(int *boBaiNguoiChoi);
int aiCo2Bich(int **BoBaiNguoiChoi);
int chonBai(int *boBaiNguoiChoi);
void choiBai(int i,int *boBaiNguoiChoi, int &quanBaiVuaChoi,int &nguoiTruoc);
void loaiNguoiChoi(int i);
int nguoiChoiTiepTheo(int i);
bool chuaAiHetBai(int **boBaiNguoiChoi);
string inQuanBai(int khoa)
{
    if (khoa==-1) return "N";
    string r="";
    int u=khoa/4;
    int v=khoa%4;
    switch (u)
    {
    case 8:
        r="10";
        break;
    case 9:
        r="J";
        break;
    case 10:
        r="Q";
        break;
    case 11:
        r="K";
        break;
    case 12:
        r="A";
        break;
    default:
        r=r+(char)(u+2+'0');
        break;
    }
    switch (v)
    {
    case 0:
        r=r+"B";
        break;
    case 1:
        r=r+"T";
        break;
    case 2:
        r=r+"R";
        break;
    case 3:
        r=r+"C";
        break;
    }
    return r;
}
bool uuTienHon(int khoa1,int khoa2)
{
    if (khoa1>khoa2) return true;
    return false;
}
void traoBai(int *boBai)
{
    int ShuffleTime=(rand()*356 + 278*rand())%100+3;
    while (ShuffleTime>0)
    {
        ShuffleTime--;
        int u=(rand()*256+rand()*123)%52;
        int v=(rand()*135+rand()*251)%52;
        swap(boBai[u],boBai[v]);
    }
}
void chiaBai(int *boBai,int **boBaiNguoiChoi)
{
    for (int i=0;i<=51;i++)
    {
        int u=i/4;
        int v=i%4;
        boBaiNguoiChoi[v][u]=boBai[i];
    }
}
void inBoBaiNguoiChoi(int *boBaiNguoiChoi)
{
    for (int i=0;i<13;i++)
        {
            //if (boBaiNguoiChoi[i]==-1) continue;
            cout << inQuanBai(boBaiNguoiChoi[i]) << " ";
        }
    cout << endl;
}
int aiCo2Bich(int **BoBaiNguoiChoi)
{
    for (int i=0;i<4;i++)
        for (int j=0;j<13;j++) if (BoBaiNguoiChoi[i][j]==0)
        {
            for (int k=j;k<12;k++) BoBaiNguoiChoi[i][k]=BoBaiNguoiChoi[i][k+1];
            BoBaiNguoiChoi[i][12]=-1;
            return i;
        }
    return -1;
}
int chonBai(int *boBaiNguoiChoi)
{
    int v=0;
    for (int i=0;i<13;i++) {if (boBaiNguoiChoi[i]==-1)break;v++;}
    int u=(rand()*258+rand()*123)%v;
    return u;
}
void choiBai(int i,int *boBaiNguoiChoi, int &quanBaiVuaChoi,int &nguoiTruoc)
{
    int u=chonBai(boBaiNguoiChoi);
    if (uuTienHon(boBaiNguoiChoi[u],quanBaiVuaChoi))
    {
        nguoiTruoc=i;
        quanBaiVuaChoi=boBaiNguoiChoi[u];
        for (int j=u;j<13;j++) boBaiNguoiChoi[j]=boBaiNguoiChoi[j+1];
        cout << "Player" << i+1 << " draw: "<<inQuanBai(quanBaiVuaChoi) << endl;
    }
    else
    {
        cout << "Loai Player" <<i+1 << " khoi vong nay" << endl;
        loaiNguoiChoi(i);
    }
}
void loaiNguoiChoi(int i)
{
    dd[i]=1;
}
int nguoiChoiTiepTheo(int i)
{
    int j=i;
    while (true)
    {
        j++;
        if (j>3) j=0;
        if (dd[j]==0) return j;
    }
    return i;
}
bool chuaAiHetBai(int **boBaiNguoiChoi)
{
    for (int i=0;i<4;i++) if (boBaiNguoiChoi[i][0]==-1) return false;
    return true;
}
void Game(int &P1Point,int &P2Point,int &P3Point,int &P4Point,int *boBai,int **boBaiNguoiChoi)
{
    traoBai(boBai);
    chiaBai(boBai,boBaiNguoiChoi);
    for (int i=0;i<4;i++){
            cout << "Player" << i+1 << ": ";
            inBoBaiNguoiChoi(boBaiNguoiChoi[i]);
    }
    int Play=aiCo2Bich(boBaiNguoiChoi);
    int quanBaiVuaChoi=0;
    cout << "Player" << Play+1 << " draw: "<<inQuanBai(quanBaiVuaChoi) << endl;
    while (chuaAiHetBai(boBaiNguoiChoi))
    {
        quanBaiVuaChoi=0;
        for (int i=0;i<4;i++) dd[i]=0;
        int t=nguoiChoiTiepTheo(Play);
        while (t!=Play&&chuaAiHetBai(boBaiNguoiChoi))
        {
            for (int i=0;i<4;i++)
                {
                    cout << "Player" << i+1 << ": ";
                    inBoBaiNguoiChoi(boBaiNguoiChoi[i]);
                }
            choiBai(t,boBaiNguoiChoi[t],quanBaiVuaChoi,Play);
            t=nguoiChoiTiepTheo(Play);
        }
        if (!chuaAiHetBai(boBaiNguoiChoi)) break;
        cout << "Ket thuc vong\n";
        for (int i=0;i<4;i++){
            cout << "Player" << i+1 << ": ";
            inBoBaiNguoiChoi(boBaiNguoiChoi[i]);
        }
        quanBaiVuaChoi=0;
        choiBai(Play,boBaiNguoiChoi[Play],quanBaiVuaChoi,Play);
    }
    for (int i=0;i<4;i++) if (boBaiNguoiChoi[i][0]==-1)
    {
        int dem=0;
        cout << "Nguoi chien thang la: Player" << i+1 << endl;
        for (int i=0;i<4;i++)
            for (int j=0;j<13;j++)
        {
            if (boBaiNguoiChoi[i][j]==-1) break;
            dem++;
        }
        switch (i+1)
        {
        case 1:
            P1Point+=dem;
            break;
        case 2:
            P2Point+=dem;
            break;
        case 3:
            P3Point+=dem;
            break;
        case 4:
            P4Point+=dem;
            break;
        }
        break;
    }
    cout << "Player1: " << P1Point << "\t" <<"Player2: "
        << P2Point << "\t"<<"Player3: " << P3Point << "\t"<<"Player4: " << P4Point << "\n";
}
int main()
{
    srand(time(NULL));
    int boBai[52];
    for (int i=0;i<=51;i++) boBai[i]=i;
    traoBai(boBai);
    int **boBaiNguoiChoi=new int*[4];
    for (int i=0;i<=3;i++)
        {
            boBaiNguoiChoi[i] = new int [15];
            boBaiNguoiChoi[i][13]=-1;
        }
    int i=1;
    int Player1=0,Player2=0,Player3=0,Player4=0;
    //Game(Player1,Player2,Player3,Player4,boBai,boBaiNguoiChoi);
    while (Player1<100&&Player2<100&&Player3<100&&Player4<100)
    {
        cout << "\tGame " << i << ":\n";
        i++;
        Game(Player1,Player2,Player3,Player4,boBai,boBaiNguoiChoi);
    }
    cout << "Nguoi thang cuoi cung la: ";
    if (Player1>99) cout << "Player1";
    if (Player2>99) cout << "Player2";
    if (Player3>99) cout << "Player3";
    if (Player4>99) cout << "Player4";
    return 0;;
}
