#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> heap;
    int arr[] = {5,1,40,10,30,20};
    int size= *(&arr+1)-arr;
    for(int i=0;i<size;i++)
        heap.push(arr[i]);
    while(!heap.empty())
    {
        cout<<heap.top()<<" ";
        heap.pop();
    }
}
