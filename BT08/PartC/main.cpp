#include <iostream>

using namespace std;
void reverse_ (char a[])
{
    char *Counter = a;
    int n=0;
    while (*Counter != NULL)
        {
            n++;
            Counter++;
        }
    for (int i=1;i<=n/2;i++)
    {
        char temp = *(a+i-1);
        *(a+i-1) = *(a+n-i);
        *(a+n-i) = temp;
    }
}
void delete_char(char a[], char c)
{
    char *Counter = a;
    int n=0;
    while (*Counter != NULL)
        {
            n++;
            Counter++;
        }
    for (int i=0;i<n;i++)
        if (a[i]==c)
    {
        for (int j=i;j<n;j++) a[j] = a[j+1];
    }
}
void pad_right(char a[], int n)
{
    char *Counter = a;
    int Count=0;
    while (*Counter != NULL)
        {
            Count++;
            Counter++;
        }
    if (Count >=n) return;
    for (int i=Count;i<n;i++) a[i]=' ';
    a[n] = NULL;
}
void pad_left(char a[], int n)
{
    char *Counter = a;
    int Count=0;
    while (*Counter != NULL)
        {
            Count++;
            Counter++;
        }
    if (Count >=n) return;
    a[n]= NULL;
    for (int i=n-1;i>= n-Count;i--) a[i]=a[Count-(n-i)];
    for (int i=0;i<n-Count;i++) a[i]= ' ';
}
void truncate(char a[], int n)
{
    char *Counter = a;
    int Count=0;
    while (*Counter != NULL)
        {
            Count++;
            Counter++;
        }
    if (Count <=n) return;
    for (int i=n;i<Count;i++) a[i]= NULL;
}
bool is_palindrome(char a[])
{
    char *Counter = a;
    int Count=0;
    while (*Counter != NULL)
        {
            Count++;
            Counter++;
        }
    for (int i=1;i<=Count/2;i++)
    {
        if (*(a+i-1) != *(a+Count-i)) return false;
    }
    return true;
}
void trim_left(char a[])
{
    char *Counter = a;
    int Count=0;
    while (*Counter != NULL)
        {
            Count++;
            Counter++;
        }
    while (a[0]==' ')
        for (int i=0;i<Count;i++) a[i]=a[i+1];
}
void trim_right(char a[])
{
    char *Counter = a;
    int Count=0;
    while (*Counter != NULL)
        {
            Count++;
            Counter++;
        }
    while (a[Count-1]==' '&& Count>0)
        {
            a[Count] = NULL;
            Count--;
        }
}
int main()
{
    char *Str = new char [20];
    int n;
    cout << "Nhap do dai xau:";
    cin >> n;
    cout << "Nhap xau:";
    for (int i=0;i<n;i++)
        cin >> Str[i];
    Str[n]=NULL;
    ///////////////////////////////////////
    cout << "Xau dao nguoc la:";
    reverse_(Str);
    int i=0;
    while (Str[i]!=NULL)
        {cout << Str[i];i++;}
    cout << endl;
    ///////////////////////////////////////
    cout << "Nhap ky tu muon xoa:";
    char del;
    cin >> del;
    delete_char(Str,del);
    cout << "Xau sau khi xoa "<< del << " la:";
    i=0;
    while (Str[i]!=NULL)
        {cout << Str[i];i++;}
    cout << endl;
    ///////////////////////////////////////
    cout << "Nhap do dai muon pad_right:";
    cin >> n;
    pad_right(Str,n);
    cout << "Xau sau khi pad_right " << n <<" ky tu:";
    i=0;
    while (Str[i]!=NULL)
        {cout << Str[i];i++;}
    cout << endl;
    ///////////////////////////////////////
    cout << "Nhap do dai muon pad_left:";
    cin >> n;
    pad_left(Str,n);
    cout << "Xau sau khi pad_left " << n <<" ky tu:";
    i=0;
    while (Str[i]!=NULL)
        {cout << Str[i];i++;}
    cout << endl;
    ///////////////////////////////////////
    cout << "Nhap do dai mong muon:";
    cin >> n;
    truncate(Str,n);
    cout << "Xau gom " << n <<" ky tu la:";
    i=0;
    while (Str[i]!=NULL)
        {cout << Str[i];i++;}
    cout << endl;
    ///////////////////////////////////////
    bool check = is_palindrome(Str);
    if (check)
    cout << "Xau doi guong\n";
    else cout << "Xau khong doi guong\n";
    //////////////////////////////////////
    trim_left(Str);
    trim_right(Str);
    i=0;
    while (Str[i]!=NULL)
        {cout << Str[i];i++;}
    return 0;
}
