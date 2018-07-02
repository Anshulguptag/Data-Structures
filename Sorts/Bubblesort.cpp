#include<iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubblesort(int A[], int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j], &A[j+1]);
            }
        }

    }
}
void print(int A[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<" ";
    }
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = *(&arr+1)-arr;

    cout<<"Unsorted array is: ";
    print(arr, size);

    bubblesort(arr, size);

    cout<<"\nSorted array is: ";
    print(arr,size);
}
