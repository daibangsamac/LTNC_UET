#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int mi=1e9,ma=-1e9;
    for (int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if (mi > x) mi=x;
        if (ma < x) ma=x;
    }
    cout << mi << endl << ma;
    return 0;
}
