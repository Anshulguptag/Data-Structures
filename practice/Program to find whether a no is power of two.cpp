#include<bits/stdc++.h>
using namespace std;

void ispowerTwo(int n)
{
    int flag = 0;
    if(n%2==0)
    {
        int quotiet = n/2;
        if(quotiet%2==0)
        {
            cout<<"Yes "<<n<<" is power of 2";
            flag=1;
        }
    }
    if(flag==0)
        cout<<"No "<<n<<" is not power of 2 ";
}

int main()
{
    ispowerTwo(6);
    cout<<"\n";
    ispowerTwo(16);
}
