#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 1, 3, 4, 2, 3};
    int size = *(&arr+1)-arr;
    int k=4;
    for(int i=0;i<size-k+1;i++)
    {
        list<int> *adj = new list<int>[10];
        int count = 0;
        for(int j=i;j<i+k;j++)
        {
            list<int>::iterator i1 = adj[arr[j]].begin();
            //cout<<*i1<<" ";
            if(*i1==NULL)
            {
                count++;
                adj[arr[j]].push_back(arr[j]);
            }
        }
        cout<<count<<" ";
    }
}
