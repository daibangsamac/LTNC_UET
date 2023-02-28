#include <iostream>

using namespace std;

int main()
{
    string Char ;
    cin >> Char;
    int n = Char.length();
    for (int i=0;i<n;i++)
    {
        string Word= "";;
        Word = Word + Char[i];
        for (int j=0;j<n;j++)
        {
            string Word2=Word+Char[j];
            cout << Word2 << " ";
            for (int k=0;k<n;k++)
            {
                string Word3=Word2+Char[k];
                cout << Word3 << " ";
            }
        }
    }
    return 0;
}
