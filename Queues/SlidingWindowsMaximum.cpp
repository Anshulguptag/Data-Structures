#include<iostream>
using namespace std;

int main()
{
    int arr[] = {1,2,3,1,4,5,2,3,6};
    int size = *(&arr+1)-arr;
    int maximum;
    for(int i=0;i<size-2;i++)
    {
        maximum = arr[i];
        for(int j=i;j<i+3;j++)
        {
            if(arr[j]>maximum)
                maximum = arr[j];
        }
        cout<<maximum<<" ";
    }
}
