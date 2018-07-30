#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> m;
    int arr[] = {5, 6, 1, 2, 3, 4};
    int n = *(&arr+1)-arr;
    for(int i=0;i<n;i++)
    {
        if(m[arr[i]]==0)
            m[arr[i]] = 1;
    }
    for(int i=0;i<n;i++)
    {
        if(m[i]!=0)
        {
            cout<<"Minimum element is: "<<i;
            break;
        }
    }
}
