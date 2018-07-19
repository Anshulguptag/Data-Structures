#include<bits/stdc++.h>
using namespace std;

void Binary(string output,int n)
{
    while(n!=0)
    {
        int rem = n%2;
        n = n/2;
        ostringstream str1;
        str1 << rem;
        string rem1 = str1.str();
        output = output+rem1;
    }
    cout<<output;
    int i;
    for(i=output.length()-1;i>=0;i--)
    {
        if(output[i]=='1')
            break;
    }
    cout<<"\n"<<i+1;
}

int main()
{
    Binary("",13);
}
