#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str = "Mr John Smith";
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==' ')
            str[i] = '%'+'2';
    }
    cout<<str;
}
