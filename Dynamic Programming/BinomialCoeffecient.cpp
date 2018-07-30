#include<bits/stdc++.h>
using namespace std;

int C(int n,int k)
{
    if(k==n || k==0)
        return 1;
    return (C(n-1,k-1) + C(n-1,k));
}

int main()
{
    cout<<C(4,2);
}
