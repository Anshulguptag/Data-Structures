#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<string> l1;
    list<string> l2;
    for(int i=0;i<2;i++)
    {
        if(i%2==0)
            l1.push_back("0");
        else
            l1.push_back("1");
    }
    for(int i=0;i<2;i++)
    {
        if(i%2==0)
            l2.push_back("1");
        else
            l2.push_back("0");
    }
    list<string>::iterator i1 = l1.begin();
    list<string>::iterator i2;
    i2=l2.begin();
    while(i1!=l1.end() && i2!=l2.end())
    {
        cout<<*i1<<" "<<*i2<<" ";
        i1++;
        i2++;
    }

}
