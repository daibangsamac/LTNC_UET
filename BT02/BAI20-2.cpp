#include <iostream>
#include <cmath>
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
    // return thue
}
long long C(long long &Loans,int &months)
{
    long long Loans_temp = Loans;
    cout << "Thang\tTongDuNoDauThang\tLaiSuatVay\tTongDuNoCuoiThang\n";
    for (int i=1;i<=months;i++)
    {
        cout << i << "\t";
        cout << Loans_temp << "\t\t\t";
        double temp = (double)Loans_temp * 2.0/100.0;
        temp=round(temp);
        cout << temp << "\t\t";
        Loans_temp +=temp;
        cout << Loans_temp << "\n";
    }
    return Loans_temp;
}
int D(int &WorkHours)
{
    long long Income_NoTax = A(WorkHours);
    long long Tax = B(Income_NoTax);
    long long Income_Tax = Income_NoTax * 91 / 100 - Tax;
    cout << "Thu nhap sau thue tu viec lam them: " << Income_Tax << endl;
    long long BankPay = Income_Tax - 500000;
    long long Loans_temp = 10000000;
    cout << "Thang\tTongDuNoDauThang\tSoTienLai\n";
    int i=0;
    while (true)
    {
        i++;
        cout << i << "\t";
        cout << Loans_temp << "\t\t";
        if (i!=1) cout << "\t";  // nhin cho dep bang thong ke
        double temp = (double)Loans_temp * 2.0/100.0;
        temp=round(temp);
        Loans_temp +=temp;
        cout << temp << "\n";
        if (Loans_temp <= BankPay) break;
        else Loans_temp-=BankPay;
    }
    return i;
}
int E(int *WorkHoursPerMonth)
{
    long long LastPay;
    long long Loans_temp = 10000000;
    cout << "Thang\tTongDuNoDauThang\tThuNhapSauThue\tSoTienLai\n";
    int i=0;
    while (true)
    {
        i++;
        cout << i << "\t";
        cout << Loans_temp << "\t\t";
        if (i!=1) cout << "\t"; // nhin cho dep bang thong ke
        int WorkHours = WorkHoursPerMonth[i];
        long long Income_NoTax = A(WorkHours);
        long long Tax = B(Income_NoTax);
        long long Income_Tax = Income_NoTax * 91 / 100 - Tax;
        long long BankPay = Income_Tax - 500000;
        cout << Income_Tax << "\t\t";
        double temp = (double)Loans_temp * 2.0/100.0;
        temp=round(temp);
        Loans_temp +=temp;
        cout << temp << "\n";
        if (Loans_temp <= BankPay)
        {
            LastPay = Loans_temp;
            break;
        }
        else Loans_temp -= BankPay;
    }
    cout << "Khoan thanh toan cuoi cung: " << LastPay << endl;
    return i;
}
int Test()
{
    int WorkHours_AB;
    cout << "WorkHours: ";
    cin >> WorkHours_AB;
    long long Income_NoTax = A(WorkHours_AB);
    cout << "Income(NoTax): " << Income_NoTax << endl;
    long long Tax = B(Income_NoTax);
    long long Income_Tax = Income_NoTax * 91 / 100 - Tax;
    cout << "Tax: " << Tax << endl;
    cout << "Income(Tax): " << Income_Tax << endl;
     /*long long tmp=3000000; cout << B(tmp);*/ //test B
    // test A,B
    ///////////////////////////////////////////////////

    cout << "Part C:\n";
    long long Loans;
    int Months_C = 12;
    cout << "Loans: ";
    cin >> Loans;
    long long Loans_AfterOneYears = C(Loans,Months_C);
    cout << "LoansAfterOneYears: " << Loans_AfterOneYears << endl;
    // test C
    ///////////////////////////////////////////////////

    cout << "Part D:\n";
    int WorkHours_D = 155;
    int Months_D = D(WorkHours_D);
    cout << "MonthsToPay: " << Months_D << endl;
    // test D
    ///////////////////////////////////////////////////

    cout << "Part E:\n";
    int WorkHoursPerMonth[20]= {0,155,145,125,135,100,100,145,135,100,155,170,180};
    int Months_E=E(WorkHoursPerMonth);
    cout << "MonthsToPay: " << Months_E << endl;
    //////////////////////////////////////////////////
}
int main()
{
    // Test();

    while (true)
    {
        cout << "Type down 1 of A B C D E\n";
        string S;
        cin >> S;
        int n = S.length();
        if (n > 1) continue ;
        if (S[0]!= 'A' && S[0]!= 'B' && S[0]!= 'C' && S[0]!= 'D' && S[0]!= 'E' && S[0]!= 'a' && S[0]!= 'b' && S[0]!= 'c' && S[0]!= 'd' && S[0]!= 'e') continue;
        if (S[0]== 'A' || S[0] == 'a')
            {
                int WorkHours;
                cout << "WorkHours: ";
                cin >> WorkHours;
                long long Income_NoTax = A(WorkHours);
                cout << "Income: " << Income_NoTax << endl;
            }
        if (S[0]== 'B' || S[0] == 'b')
            {
                int WorkHours;
                cout << "WorkHours: ";
                cin >> WorkHours;
                long long Income_NoTax = A(WorkHours);
                //cout << "Income(NoTax): " << Income_NoTax << endl;
                long long Tax = B(Income_NoTax);
                long long Income_Tax = Income_NoTax * 91 / 100 - Tax;
                cout << "Tax: " << Tax << endl;
                cout << "Income(Tax): " << Income_Tax << endl;
        }
        if (S[0]== 'C' || S[0] == 'c')
            {
                long long Loans;
                int Months_C = 12;
                cout << "Loans: ";
                cin >> Loans;
                long long Loans_AfterOneYears = C(Loans,Months_C);
                cout << "LoansAfterOneYears: " << Loans_AfterOneYears << endl;
            }
        if (S[0]== 'D' || S[0] == 'd')
            {
                int WorkHours = 155;
                int Months_D = D(WorkHours);
                cout << "MonthsToPay: " << Months_D << endl;
            }
        if (S[0]== 'E' || S[0] == 'e')
            {
                int WorkHoursPerMonth[20]= {0,155,145,125,135,100,100,145,135,100,155,170,180};
                int Months_E=E(WorkHoursPerMonth);
                cout << "MonthsToPay: " << Months_E << endl;
            }
    }
    return 0;
}
