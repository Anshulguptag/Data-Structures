/*if we have n number of nodes than leaf nodes are starting from floor(n/2)+1 to n
Max-Heapify(A,i)
{
    l = 2i;
    r = 2i+1;
    if(l<=A.heapsize and A[l]>A[i])
        largest = l;
    else
        largest = i;
    if(r<=A.heapsize and A[r]>A[largest])
        largest = r;
    if(largest!=i)
        exchange A[i] with A[largest]
        Max-Heapify(A,largest)
}

consider heap is : 11 14 10 8 7 9 3 2 4 6
                   11
                /     \
               14      10
             /   \    /  \
            8     7  9    3
           / \   /
          2   4 6

 leaf start from : floor(10/2)+1 to 10 = index 6(9) to index 10(6)


*/

#include<bits/stdc++.h>
using namespace std;

void Heapify(int arr[],int i,int size)
{
    int l = 2*i;
    int r = 2*i+1;
    int largest;
    if(l<=size && arr[i]<arr[l])
        largest = l;
    else
        largest = i;
    if(r<=size && arr[largest]<arr[r])
        largest = r;
    if(largest!=i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = arr[i];

        Heapify(arr,largest,size);
    }
}

int main()
{
    int arr[30];
    arr[1] = 11;
    arr[2] = 14;
    arr[3] = 10;
    arr[4] = 8;
    arr[5] = 7;
    arr[6] = 9;
    arr[7] = 3;
    arr[8] = 2;
    arr[9] = 4;
    arr[10] = 6;
    int n = 10;

    for(int i=floor(n/2)+1;i>=1;i--)
        Heapify(arr,i,n);

    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";

}
