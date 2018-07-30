#include<bits/stdc++.h>
using namespace std;


string Roman(map<int,string> m,int n,int arr[])
{
    string output;

    while(n!=0)
    {
        int divisor=0;
        for(int i=11;i>0;i--)
        {
            if(n-arr[i]>=0)
            {
               divisor = arr[i];
               break;
            }
        }
        int quotient = n/divisor;
        while(quotient!=0)
        {
            output = output + m[divisor];
            quotient--;
        }
        n=n%divisor;
    }
    return output;
}

int main()
{
    int arr[] = {1,4,5,9,10,40,50,90,400,500,900,1000};
    map<int,string> m;
    m[1]="I";
    m[4]="IV";
    m[5]="V";
    m[9]="IX";
    m[10]="X";
    m[40]="XL";
    m[50]="L";
    m[90]="XC";
    m[400]="CD";
    m[500]="D";
    m[900]="CM";
    m[1000]="M";
    cout<<Roman(m,1904,arr);
}
