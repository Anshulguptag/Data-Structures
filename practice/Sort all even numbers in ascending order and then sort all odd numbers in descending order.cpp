#include<bits/stdc++.h>
using namespace std;

//Insertion Sort

void Sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j = i;
        while(j!=0)
        {
            if(arr[j]<arr[j-1])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            j--;
        }
    }
}

int main()
{
    int arr[] ={0,4,5,3,7,2,1};
    int n= *(&arr+1)-arr;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2!=0)
            arr[i]=-1*arr[i];
    }
    Sort(arr,n);
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
            arr[i] = -1*arr[i];
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
