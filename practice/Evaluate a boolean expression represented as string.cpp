#include<bits/stdc++.h>
using namespace std;

int OR(int x,int y)
{
    if(x==0 && y==0)
        return 0;
    return 1;
}

int AND(int x,int y)
{
    if(x==1 && y==1)
        return 1;
    return 0;
}

int XOR(int x,int y)
{
    if(x==y)
        return 1;
    return 0;
}


int main()
{
    string str = "1C1B1B0A0";
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='A')
            str[i+1] = (char)(AND(str[i-1]-'0',str[i+1]-'0')+'0');
        if(str[i]=='B')
            str[i+1] = (char)(OR(str[i-1]-'0',str[i+1]-'0')+'0');
        if(str[i]=='C')
            str[i+1] = (char)(XOR(str[i-1]-'0',str[i+1]-'0')+'0');
    }
    cout<<str[str.length()-1];
}
