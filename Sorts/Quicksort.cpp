#include<iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int start, int end)
{
  int pivot = A[end];
  int pIndex = start;
  for (int i=start;i<end;i++)
  {
      if(A[i]<=pivot)
      {
          swap(&A[i], &A[pIndex]);
          pIndex = pIndex+1;
      }
  }
  swap(&A[pIndex],&A[end]);
  return pIndex;
}

void quicksort(int A[],int start, int end)
{
    if(start<end)
    {
        int pIndex = partition(A,start, end);
        quicksort(A,start,pIndex-1);
        quicksort(A,pIndex+1,end);
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
    int arr[] = {12,13,11,5,8,7,2};
    int size = *(&arr+1)-arr;

    cout<<"Unsorted array: ";
    print(arr,size);

    quicksort(arr,0,size-1);

    cout<<"\nSorted array: ";
    print(arr,size);
}
