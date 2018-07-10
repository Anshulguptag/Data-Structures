#include<iostream>
using namespace std;

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int arr[] = {7,3,2,1,8,10,11};
    for(int i=0;i<6;i++)
    {
        for(int j=i+1;j<7;j++)
            if(arr[i]>arr[j])
                Swap(&arr[i],&arr[j]);
    }
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
}
