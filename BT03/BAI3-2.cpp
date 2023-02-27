#include <iostream>

using namespace std;
int a[10];
int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i=0;i<10;i++) cout << i << " " << a[i] << endl;
    return 0;
}
