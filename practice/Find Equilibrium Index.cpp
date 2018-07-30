#include<bits/stdc++.h>
using namespace std;

int Sum(int index,int n,int arr[])
{
    int sum=0;
    for(int j=index;j<n;j++)
    {
        sum = sum +arr[j];
    }
    return sum;
}

int FindEquilibrium(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        if(Sum(0,i,arr)==Sum(i+1,size,arr))
            return i;
    }
    return -1;
}

int main()
{
    int arr[] ={2, -2, 3, 2, -2, -3, 3, 0};
    int size = *(&arr+1)-arr;
    int EquiIndex = FindEquilibrium(arr,size);
    if(EquiIndex!=-1)
        cout<<EquiIndex<<" is equilibrium index";
    else
        cout<<"No equilibrium in the given array ";

}
