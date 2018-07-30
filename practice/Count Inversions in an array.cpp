#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 20, 6, 4, 5, 100, 30, 3, 0};
    int size = *(&arr+1)-arr;
    int count1 = 0;
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            if(arr[i]>arr[j] && i<j)
            {
             cout<<"("<<arr[i]<<","<<arr[j]<<") ";
             count1++;
            }
        }
    }
    cout<<"\n"<<count1;
}
