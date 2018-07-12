#include<iostream>
#include<list>
#include<queue>

using namespace std;

queue<int> temppath;
queue<int> path;
list<int> *adj = new list<int>[8];
int count;

void findShortPath(int x,int y,char ch[],int *count,bool visited[])
{
    visited[x]=true;
    temppath.push(x);
    *count = *count+1;
    if(x!=y)
        {
            list<int>::iterator i;
            for(i=adj[x].begin();i!=adj[x].end();i++)
            {
              if(!visited[*i])
                   return findShortPath(*i,y,ch,count,visited);
            }
        }

}

void findPath(int x,int y,char ch[])
{
   list<int>::iterator i;
   int count,k=10;
   bool *visited = new bool[8];
   for(i=adj[x].begin();i!=adj[x].end();i++)
   {
       count = 0;
       for (int j = 0; j < 8; j++)
            visited[j] = false;
       visited[x]=true;
       findShortPath(*i,y,ch,&count,visited);
       if(k>count)
       {
           while(!path.empty())
           {
               path.pop();
           }
       }
        while(!temppath.empty())
        {
            if(k>count)
                path.push(temppath.front());
            temppath.pop();
        }
       k=count;
   }
}

void addEdge(char a,char b,char ch[],int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        if(ch[i]==a)
            break;
    }
    for(j=0;j<size;j++)
    {
        if(ch[j]==b)
            break;
    }

    adj[i].push_front(j);
    adj[j].push_back(i);
}

int findIndex(char a,char ch[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(a==ch[i])
            break;
    }
    return i;
}
int main()
{
    char ch[] = {'A','B','C','D','E','F','G','H'};
    int size = *(&ch+1)-ch;
    addEdge('A','B',ch,size);
    addEdge('A','C',ch,size);
    addEdge('A','F',ch,size);
    addEdge('B','D',ch,size);
    addEdge('C','E',ch,size);
    addEdge('D','E',ch,size);
    addEdge('F','G',ch,size);
    addEdge('G','E',ch,size);
    addEdge('G','H',ch,size);
    addEdge('H','E',ch,size);

    list<int>::iterator i;

    for(int j=0;j<size;j++)
    {
        cout<<"From "<<ch[j]<<"-->";
        for(i=adj[j].begin();i!=adj[j].end();i++)
            cout<<ch[*i]<<" ";
        cout<<"\n";
    }

    /*
    My Graph
      B---D
     /     \
    A---C---E
     \     /
      F-G-H
    */


    cout<<"\nEnter the Source Node: ";
    char x;
    cin>>x;
    cout<<"\nEnter the Destination Node: ";
    char y;
    cin>>y;
    findPath(findIndex(x,ch,size),findIndex(y,ch,size),ch);
    cout<<"\nshortest path from "<<ch[findIndex(x,ch,size)]<<" to "<<ch[findIndex(y,ch,size)]<<": "<<ch[findIndex(x,ch,size)];
    while(!path.empty())
    {
        cout<<ch[path.front()];
        path.pop();
    }
}
