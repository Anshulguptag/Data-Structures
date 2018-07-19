#include<bits/stdc++.h>
using namespace std;

int Replace(int n)
{
    int i=0;
    int sum=0;
    while(n!=0)
    {
        int rem = n%10;
        n = n/10;
        if(rem==0)
        {
            sum = sum+pow(10,i)*5;

            cout<<pow(10,i)<<" "<<sum<<"\n";
        }

        else
        {
            sum = sum+pow(10,i)*rem;
            cout<<pow(10,i)<<" "<<sum<<"\n";
        }
        i++;
    }
    return sum;
}

int main()
{
    cout<<Replace(10120);
}
