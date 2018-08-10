#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

list<int> *adj = new list<int>[MAX];

void makeboolarray(bool visited[],int n)
{
    for(int i=0;i<n;i++)
        visited[i] = false;
}

bool isCycle(int n,bool visited[],int arr[])
{
    if(visited[n]==false)
        visited[n] = true;
    else
        return false;
    list<int>::iterator i1;
    for(i1=adj[n].begin();i1!=adj[n].end();i1++)
    {
        if(!visited[*i1])
            isCycle(arr[*i1],visited,arr);
    }
    return true;
}

void checkgraph(int arr[],int n)
{
  bool visited[n];
  makeboolarray(visited,n);
  for(int i=0;i<n;i++)
  {
      if(!isCycle(arr[i],visited,arr))
      {
          cout<<"Cycle Detected";
          return;
      }
  }
  cout<<"No cycle detected";
}
void Insert(int x,int y)
{
    adj[x].push_back(y);
}

int main()
{
    int arr[] = {2,3,1,4};

    Insert(2,3);
    Insert(3,1);
    Insert(1,2);
    Insert(1,4);

    int n = *(&arr+1)-arr;
    checkgraph(arr,n);
}
