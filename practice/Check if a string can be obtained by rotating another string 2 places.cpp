#include<bits/stdc++.h>
using namespace std;

void Rotate(string a,string a2)
{
    int i,count=0;
    string a1 = a;
    char first = a1[a1.length()-1];
    char second = a1[a1.length()-2];
    for(i=a1.length()-1;i>0;i--)
        a1[i] = a1[i-2];
    a1[0] = second;
    a1[1] = first;
    if(a1==a2)
    {
        cout<<"Obtained by rotating clockwise from "<<a<<" to "<<a1;
        return;
    }
    a1 = a;
    first = a1[0];
    second = a1[1];
    for(i=0;i<a1.length();i++)
        a1[i] = a1[i+2];
    a1[a1.length()-1] = second;
    a1[a1.length()-2] = first;
    if(a1==a2)
    {
        cout<<"Obtained by rotating anti-clockwise from "<<a<<" to "<<a1;
        return;
    }
}
int main()
{
    Rotate("azonam","amazon");
    cout<<"\n";
    Rotate("onamaz","amazon");
}
