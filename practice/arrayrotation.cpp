#include<bits/stdc++.h>
using namespace std;

void Rotation(int arr[],int d,int size)
{
    int rot =0;
    for(;rot<d;rot++)
    {
        int a =arr[0];
        for(int i=0;i<size-1;i++)
            arr[i] = arr[i+1];
        arr[size-1] = a;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    Rotation(arr,2,7);
    for (int i=0;i<7;i++)
        cout<<arr[i];
}
