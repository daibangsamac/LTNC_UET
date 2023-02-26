#include <iostream>

using namespace std;
long long f[100005];
long long fib(int i)
{
    if (f[i]!=0) return f[i];
    if (i==1||i==2) return f[i]=1;
    return f[i]=fib(i-1) + fib(i-2);
}
int main()
{
    int n;
    cin >> n;
    int i=1;
    while (true)
    {
        long long t=fib(i);
        i++;
        if (t > n) break;
        cout << t << endl;
    }
    return 0;
}
