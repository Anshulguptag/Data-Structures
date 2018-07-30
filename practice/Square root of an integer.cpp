#include<bits/stdc++.h>
using namespace std;

int floorSqrt(int x)
{
    int i=1;
    int result =1;
    while(result<=x)
    {
        i++;
        result = i*i;
    }
    return i-1;
}


int main()
{
    int n;
    cout<<"Enter the number do you wan to find a square root: ";
    cin>>n;
    cout<<"Square Root of number "<<n<<" is: "<<floorSqrt(n);
}
