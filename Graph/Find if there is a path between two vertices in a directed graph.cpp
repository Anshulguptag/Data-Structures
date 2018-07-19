#include<bits/stdc++.h>
using namespace std;

list<int> *adj = new list<int>[100];

void Insert(int x,int y)
{
    adj[x].push_back(y);
}

int getIndex(char a,char ch[],int size)
{
    for(int i=0;i<size;i++)
    {
        if(ch[i]==a)
            return i;
    }
}
bool isPath(char b,int i,char ch[],bool visited[])
{

    visited[i] = true;

    if(ch[i]==b)
    {
       return true;
    }

    list<int>::iterator i1;
    for(i1 = adj[i].begin();i1!=adj[i].end();i1++)
    {
        if(!visited[*i1])
            if(isPath(b,*i1,ch,visited))
                return true;

    }
}
void findpath(char a,char b,char ch[],int size)
{
    bool visited[size];
    for(int i=0;i<size;i++)
        visited[i] = false;

    int source = getIndex(a,ch,size);
    list<int>::iterator i1;

    visited[source] = true;
    for(i1=adj[source].begin();i1!=adj[source].end();i1++)
        if(isPath(b,*i1,ch,visited))
        {
           cout<<"Path found between "<<a<<" and "<<b;
            return;
        }
    cout<<"\nNo path found between "<<a<<" and "<<b;

}
int main()
{
    char ch[] ={'A','B','C','D'};
    int size = *(&ch+1)-ch;
    Insert(getIndex('A',ch,size),getIndex('B',ch,size));
    Insert(getIndex('A',ch,size),getIndex('C',ch,size));
    Insert(getIndex('C',ch,size),getIndex('A',ch,size));
    Insert(getIndex('C',ch,size),getIndex('D',ch,size));
    Insert(getIndex('D',ch,size),getIndex('D',ch,size));
    Insert(getIndex('B',ch,size),getIndex('C',ch,size));
    /*

    A----->B
    ^      /
    |     /
    |    /   --|
    |   /    | |
    \/|_     \/|
    C ----->D---
    */
    list<int>::iterator i1;
    for(int j=0;j<size;j++)
    {
        cout<<"["<<ch[j]<<"]";
        for(i1=adj[j].begin();i1!=adj[j].end();i1++)
            cout<<"->"<<ch[*i1];
        cout<<"\n";
    }
   findpath('B','D',ch,size);
   findpath('D','B',ch,size);

}
