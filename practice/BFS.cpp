#include<bits/stdc++.h>
using namespace std;

list<int> *adj = new list<int>[100];

void Traverse()
{
    list<int>::iterator i1;
    bool visited[] = {false,false,false,false,false,false};
    for(int i=1;i<=6;i++)
    {
        if(!visited[i-1])
            {
                cout<<i<<" ";
                visited[i-1] = true;
            }
        for(i1=adj[i].begin();i1!=adj[i].end();i1++)
        {
            if(!visited[*i1-1])
            {
                cout<<*i1<<" ";
                visited[*i1-1] = true;
            }
        }
    }
}

void Insert(int x,int y)
{
    adj[x].push_back(y);
}

int main()
{
    Insert(1,2);
    Insert(1,3);
    Insert(2,4);
    Insert(2,5);
    Insert(3,5);
    Insert(4,6);
    Insert(5,6);

    Traverse();
}
