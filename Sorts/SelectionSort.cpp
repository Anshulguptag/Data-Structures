#include<iostream>
using namespace std;

void swap(int *x, int*y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionsort(int A[], int size)
{
    int min ,index=0;
    for(int i=0;i<size-1; i++)
    {
        min=A[i];
        for(int j=i+1; j<size; j++)
        {
            if(A[j]<min)
            {
                min = A[j];
                index = j;
            }

        }
        swap(&A[i], &A[index]);
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

    selectionsort(arr,size);

    cout<<"\nSorted array is: ";
    print(arr,size);
}
