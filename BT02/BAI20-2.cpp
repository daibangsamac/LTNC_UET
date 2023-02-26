#include <iostream>

using namespace std;
long long A(int &WorkHours)
{
    long long Income = 0;
    int WorkHours_temp = WorkHours;
    if ( WorkHours_temp > 200 )
        {
            Income += (long long)(WorkHours_temp - 200) * 25000;
            WorkHours_temp = 200;
        }
    if ( WorkHours_temp > 150 )
        {
            Income += (long long)(WorkHours_temp - 150) * 20000;
            WorkHours_temp = 150;
        }
    if ( WorkHours_temp > 100 )
        {
            Income += (long long)(WorkHours_temp - 100) * 16000;
            WorkHours_temp = 100;
        }
    if ( WorkHours_temp == 100) Income += (long long) 100* 12000;
    return Income;
}
long long B(long long &Income_NoTax)
{
    long long Tax = 0;
    long long Income_NoTax_temp = Income_NoTax;
    Income_NoTax_temp = Income_NoTax_temp * 91 / 100;
    if ( Income_NoTax_temp > 2000000 )
    {
        Tax += (Income_NoTax_temp - 2000000) * 20/100;
        Income_NoTax_temp = 2000000;
    }
    if ( Income_NoTax_temp > 1500000 )
    {
        Tax += (Income_NoTax_temp - 1500000) * 15/100;
        Income_NoTax_temp = 1500000;
    }
    if ( Income_NoTax_temp > 1000000 )
    {
        Tax += (Income_NoTax_temp - 1000000) * 10/100;
        Income_NoTax_temp = 1000000;
    }
    return Tax;
}
long long C()
{
}
int D(){}
int E(){}
int main()
{
    int WorkHours;
    cout << "WorkHours: ";
    cin >> WorkHours;
    long long Income_NoTax = A(WorkHours);
    cout << "Income(NoTax): " << Income_NoTax << endl;
    long long Tax = B(Income_NoTax);
    long long Income_Tax = Income_NoTax * 91 / 100 - Tax;
    cout << "Tax: " << Tax << endl;
    cout << "Income(Tax): " << Income_Tax << endl;
    C();
    D();
    E();
    /*long long tmp=3000000; cout << B(tmp);*/ //test B
    return 0;
}
