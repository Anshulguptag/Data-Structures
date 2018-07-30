#include<bits/stdc++.h>
using namespace std;

void Reverse(string str)
{
    for(int i=0;i<(str.length())/2;i++)
    {
      char temp = str[i];
      str[i] = str[str.length()-i-1];
      str[str.length()-i-1] = temp;
    }
    cout<<str<<"\n";
}

void String(int n)
{
    char str[90];
    int i=0;
    while(n>0)
    {
        int rem = n%26;
        if(rem==0)
        {
            str[i++] = 'Z';
            n = (n/26)-1;
        }
        else
        {
            str[i++] = (rem-1) + 'A';
            n = n/26;
        }
    }
    str[i++] = '\0';
    Reverse(str);
}

int main()
{
    String(52);
    String(56);
}
