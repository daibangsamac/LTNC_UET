#include <iostream>

using namespace std;
struct String
{
    int n=0;
    char *Str = new char[20];
    String(const char* Str_) {while (Str_[n]!=NULL) {Str[n]=Str_[n];n++;}Str[n]=NULL;}
    ~String() {delete Str;}
    void print(){int i=0;while(Str[i]!=NULL) {cout << Str[i];i++;}cout << endl;}
    void append(const char* Str_)
    {
        int i=0;
        while (Str_[i]!=NULL)
        {
            Str[i+n] = Str_[i];
            i++;
        }
        n=n+i;
        Str[n]= NULL;
    }
};
int main()
{
    String s=String("Hi");
    s.print();
    s.append(" there");
    s.print();
    return 0;
}
