#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"Enter value of k: ";
    cin>>k;
    int q;
    if(n*k<0)
    {
      q = k*(floor(n/k)-1);
    }
    else
      q = k*(floor(n/k));
    cout<<"The number closest to "<<n<<" and divisible by "<<k<<" is: "<<q;
}
