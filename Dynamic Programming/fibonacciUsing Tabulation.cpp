
#include<iostream>

using namespace std;

int fibonacci(int n)
{
    int f[n];
    f[0] = 0, f[1] =1;
    int i;
    for(i=2;i<=n;i++)
        f[i] = f[i-1] + f[i-2];


    return f[n];
}

int main()
{
    cout<<fibonacci(8);
}
