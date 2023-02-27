#include <iostream>
#include <iomanip>
using namespace std;
int a[20][20];
int main()
{
    int n;
    cin >> n;
    a[1][1]=1;
    cout << setw(4) << 1 << setw(4) << endl;
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
                cout << a[i][j] << setw(4);
            }
        cout << endl;
    }
    return 0;
}
