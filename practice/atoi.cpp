#include<bits/stdc++.h>
using namespace std;

int Atoi(string str)
{
    int sum = 0;
    for(int i=0;i<str.length();i++)
        sum = sum + pow(10,str.length()-i-1)*(int(str[i])-'0');
    return sum;
}

int main()
{
    cout<<Atoi("8978989");
}
