#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int rollDice()
{
    int q=rand()*91 % 6 +1;
    return q;
}
void Cach1()
{
    cout << "Cach A:\n";
    int p1=0,p2=0,t=0;
    while (p1<100 && p2 <100)
    {
        t=t%2 +1;
        int point=rollDice();
        if (t==1) {cout << "xuc xac nguoi choi 1: " << point << " Tong nguoi 1: ";p1+=point;cout << p1 << endl;}
        if (t==2) {cout << "xuc xac nguoi choi 2: " << point << " Tong nguoi 2: ";p2+=point;cout << p2 << endl;}
    }
}
void Cach2()
{
    cout << "Cach B:\n";
    int p1=0,p2=0,t=1;
    while (p1<100 && p2 <100)
    {
        if (p1<p2) t=1;
        if (p2<p1) t=2;
        int point=rollDice();
        if (t==1) {cout << "xuc xac nguoi choi 1: " << point << " Tong nguoi 1: ";p1+=point;cout << p1 << endl;}
        if (t==2) {cout << "xuc xac nguoi choi 2: " << point << " Tong nguoi 2: ";p2+=point;cout << p2 << endl;}
    }
}
int main()
{
    srand(time(0));
    Cach1();
    Cach2();
    return 0;
}
