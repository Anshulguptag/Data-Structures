//Using Memoization
#include<bits/stdc++.h>
using namespace std;

int lookup[10];

void initialize()
{
    for(int i=0;i<10;i++)
       lookup[i] =NULL;
}

int fib(int n)
{
    if(lookup[n]==NULL)
    {
        if(n<=1)
            lookup[n] = n;
        else
            lookup[n] = fib(n-2)+fib(n-1);
    }
    return lookup[n];
}

int main()
{
    initialize();
    cout<<fib(8);

}
