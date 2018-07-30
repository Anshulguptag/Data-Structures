#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 5, 6, 3, 7, 8};
    int size = *(&arr+1)-arr;
    int sum = ((size+1)*(size+2))/2;
    for (int i=0;i<size;i++)
        sum = sum-arr[i];
    cout<<sum;
}
