#include <iostream>
#include <string>
using namespace std;
string NTS(int x)
{
    string r="";
    while (x>0)
    {
        char c=(char)(x%10 + '0');
        r=c+r;
        x=x/10;
    }
    return r;
}
string NTE(string x)
{
    string r="";
    int n=x.length();
    if (n==3)
    {
        switch ((int) (x[0]-'0'))
        {
        case 1:
            r="one hundred ";
            break;
        case 2:
            r="two hundred ";
            break;
        case 3:
            r="three hundred ";
            break;
        case 4:
            r="four hundred ";
            break;
        case 5:
            r="five hundred ";
            break;
        case 6:
            r="six hundred ";
            break;
        case 7:
            r="seven hundred ";
            break;
        case 8:
            r="eight hundred ";
            break;
        case 9:
            r="nine hundred ";
            break;
        default:
            break;
        }
        x.erase(0,1);
        n--;
    }
    if (n==2)
    {
        switch ((int)(x[0]-'0'))
        {
        case 1:
            switch ((int)(x[1]-'0'))
            {
            case 0:
                r=r+ "ten ";
                break;
            case 1:
                r=r+ "eleven ";
                break;
            case 2:
                r=r +"twelve ";
                break;
            case 3:
                r=r+ "thirteen ";
                break;
            case 4:
                r=r+ "fourteen ";
                break;
            case 5:
                r=r+ "fifteen ";
                break;
            case 6:
                r=r+ "sixteen ";
                break;
            case 7:
                r=r+ "seventeen ";
                break;
            case 8:
                r=r+ "eighteen ";
                break;
            case 9:
                r=r+ "nineteen ";
                break;
            }
            return r;
            break;
        case 2:
            r= r + "twenty ";
            break;
        case 3:
            r= r + "thirty ";
            break;
        case 4:
            r= r + "forty ";
            break;
        case 5:
            r= r + "fifty ";
            break;
        case 6:
            r= r + "sixty ";
            break;
        case 7:
            r= r + "seventy ";
            break;
        case 8:
            r= r + "eighty ";
            break;
        case 9:
            r= r + "ninety ";
            break;
        }
        x.erase(0,1);
        n--;
    }
    if (n==1)
    {
        switch ((int) (x[0]-'0'))
        {
        case 1:
            r=r+"one";
            break;
        case 2:
            r=r+"two";
            break;
        case 3:
            r=r+"three";
            break;
        case 4:
            r=r+"four";
            break;
        case 5:
            r=r+"five";
            break;
        case 6:
            r=r+"six";
            break;
        case 7:
            r=r+"seven";
            break;
        case 8:
            r=r+"eight";
            break;
        case 9:
            r=r+"nine";
            break;
        default:
            break;
    }
    }
    return r;
}
int main()
{
    int n;
    cin >> n;
    if (n==0) {cout << "zero"; return 0;}
    string res="";
    bool p=false;
    if (n+abs(n)==0) {p=true;;n=abs(n);}
    int tmp1=0;
    while (n>0)
    {
        tmp1++;
        int tmp2=n%1000;
        n=n/1000;
        string tmp3=NTE(NTS(tmp2));
        if (tmp1==2) {res="million " + res;}
        if (tmp1==3) {res="billion " + res;}
        res=tmp3 + " " +res;
    }
    if (p) res = "negative " + res;
    cout << res;
    return 0;
}
