#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;
int a[102];
void CreateBoard(int n)
{
    srand(time(NULL));
    for (int i=1;i<=n;i++)
        a[i]=rand()%50;
}
int main()
{
    int n;
    cin >> n;
    CreateBoard(n);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            for (int k=j+1;k<=n;k++)
            if ((a[i]+a[j]+a[k]) %25 ==0) cout << i << " " << j << " " << k << endl;
    return 0;
}
