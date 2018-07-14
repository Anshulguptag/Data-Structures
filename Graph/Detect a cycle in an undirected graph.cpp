/*DFS is used*/

#include<iostream>
#include<list>
#include<queue>

using namespace std;

list<int> *adj = new list<int>[8];

void DetectCycle(int x,int y,char ch[],bool visited[],int *temp)
{
    visited[x]=true;
    if(x!=y)
        {
            list<int>::iterator i;
            for(i=adj[x].begin();i!=adj[x].end();i++)
            {
                if(ch[*adj[x].begin()]!=ch[y] && !visited[*i])
                    DetectCycle(*i,y,ch,visited,temp);
            }
        }
     else
        {
         cout<<"Graph Contain Cycle";
         *temp = -1;
         return;
        }

}

void takegraph(int x,char ch[])
{
   list<int>::iterator i;
   bool *visited = new bool[8];
   int temp;
   for(i=adj[x].begin();i!=adj[x].end();i++)
   {
       for (int j = 0; j < 8; j++)
            visited[j] = false;
        DetectCycle(*i,x,ch,visited,&temp);
        if(temp==-1)
           break;
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
    adj[j].push_front(i);
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
    char ch[] = {'A','B','C','D','E'};
    int size = *(&ch+1)-ch;
    addEdge('A','B',ch,size);
    addEdge('B','C',ch,size);
    addEdge('C','D',ch,size);
    addEdge('D','E',ch,size);
    addEdge('E','A',ch,size);
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
      B
     / \
    A---C
    */


    cout<<"\nEnter the Source Node: ";
    char x;
    cin>>x;
    takegraph(findIndex(x,ch,size),ch);

}
