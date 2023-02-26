#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i=n;i>=1;i--)
        {
            int tmp=n-i;
    for (int j=1;j<=2*n+1;j++)
        if (j<=(n+tmp) && j >=(n-tmp)) cout << "*";
    else cout << " ";
    cout << endl;
        }
    return 0;
}
