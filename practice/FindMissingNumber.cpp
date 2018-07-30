#include<bits/stdc++.h>
using namespace std;

list<int> *adj = new list<int>[100];




int main()
{
    int arr[] = {1, 2, 4, 6, 3, 7, 8};
    int size = *(&arr+1)-arr;
    for(int i=0;i<size;i++)
    {
        adj[arr[i]].push_back(arr[i]);
    }
    list<int>::iterator i1;
    for(int j=1;j<size;j++)
    {
        i1=adj[j].begin();
        if(*i1==0)
        {
            cout<<j<<" is missing";
            break;
        }
    }
}
