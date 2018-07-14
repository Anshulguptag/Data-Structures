#include<iostream>
#include<list>
#define MAX 70
using namespace std;

list<int> *adj = new list<int>[MAX];

int hashfunction(int x,int size)
{
    return x%size;
}

void Insert(int x,int size)
{
    adj[hashfunction(x,size)].push_back(x);
}

void Search(int x,int size)
{
    cout<<"["<<hashfunction(x,size)<<"]-->"<<x;
}

int main()
{
    int arr[] = {15,19,8,3,10,12};
    int size = *(&arr+1)-arr;
    for(int i=0;i<size;i++)
    {
        Insert(arr[i],size);
    }

    list<int>::iterator k;
    for(int j=0;j<size;j++)
    {
        cout<<"["<<j<<"]";
        for(k=adj[j].begin();k!=adj[j].end();k++)
        {
            cout<<"-->"<<*k;
        }
        cout<<"\n";
    }

    cout<<"\n15 found at:";
    Search(15,size);
}
