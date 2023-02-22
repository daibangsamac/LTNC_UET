#include <iostream>

using namespace std;

int main()
{
    double tb=0;
    int n,x,mi=1e9+7,ma=-1e9+7;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> x;
        tb += x;
        mi = min (mi,x);
        ma = max (ma,x);
    }
    tb = tb/ (double)n;
    cout << "Mean: " << tb << endl;
    cout << "Max: " << ma << endl;
    cout << "Min: " << mi << endl;
    return 0;
}
