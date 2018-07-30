#include<bits/stdc++.h>
using namespace std;

int MAX(int LIS[],int size)
{
    int Max = LIS[0];
    for(int i=0;i<size;i++)
    {
        if(Max<LIS[i])
            Max = LIS[i];
    }
    return Max;
}

int Lis(int arr[],int size,int LIS[])
{
    for(int i=1;i<size;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
                LIS[i] = max(LIS[j]+1,LIS[i]);
        }
    }
    return MAX(LIS,size) ;
}

int main()
{
    int arr[] = {10,22,9,33,21,50,41,60};
    int size = *(&arr+1) - arr;
    int *LIS = new int[size];
    for(int i=0;i<size;i++)
        LIS[i] = 1;
    cout<<Lis(arr,size,LIS);
    delete LIS;

}
