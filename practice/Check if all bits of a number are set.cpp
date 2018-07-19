#include<bits/stdc++.h>
using namespace std;

bool isSet(string str)
{
    for(int i=0;i<str.length();i++)
    {
        if((int)str[i]==0)
            return false;
    }
    return true;
}

void findisSet(int n)
{
    string output = "";
    while(n!=0)
    {
        int rem = n%2;
        n = n/2;
        output = output + (char)rem;
    }
    cout<<((n+1) & n);
    if(isSet(output))
        cout<<"Yes";
    else
        cout<<"N0";
}

int main()
{
    findisSet(7);
}
