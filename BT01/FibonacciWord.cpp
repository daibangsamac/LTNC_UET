#include <iostream>

using namespace std;

int main()
{
    string f0= "a";
    string f1= "b";
    string f;
    cout << f0 << endl;
    cout << f1 << endl;
    for (int i=2;i<11;i++)
    {
        f=f1+f0;
        cout << f << endl;
        f0=f1;
        f1=f;
    }
    return 0;
}
