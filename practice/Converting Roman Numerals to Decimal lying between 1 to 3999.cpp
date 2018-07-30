#include<bits/stdc++.h>
using namespace std;

map<string, int> m;

void Convert2Roman(string str)
{
    string output = "";
    int sum = 0;
    for(int i=0;i<str.length();)
    {
        int j =2 ;
        while(j!=0)
        {
            //cout<<str.substr(i,j)<<" ";
            if(m[str.substr(i,j)]!=0)
            {
                sum = sum + m[str.substr(i,j)];
                break;
            }
            j--;
        }
        i = i+j;
    }
    cout<<sum;
}


int main()
{
    m["I"] = 1;
    m["IV"] = 4;
    m["V"] = 5;
    m["IX"] = 9;
    m["X"] = 10;
    m["XL"] = 40;
    m["L"] = 50;
    m["XC"] = 90;
    m["C"] = 100;
    m["CD"] = 400;
    m["D"] = 500;
    m["CM"] = 900;
    m["M"] = 1000;

    Convert2Roman("MCCLXIX");
}
