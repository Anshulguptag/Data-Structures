#include<iostream>
using namespace std;

int main()
{
    int arr[] = {16,17,4,3,5,2};
    int max1;
    for(int i=0;i<5;i++)
    {
        max1 = arr[i+1];
        for(int j=i+1;j<6;j++)
        {
            if(arr[j+1]>max1)
                max1 = arr[j+1];
        }
        arr[i] = max1;
    }
    arr[5] = -1;
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";

}
