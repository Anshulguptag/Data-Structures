#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n =32;
    int output=0,i=1;
    while(1)
    {
        if(pow(2,i)>n)
            break;
        output = pow(2,i);
        i++;
    }
    cout<<output;
}
