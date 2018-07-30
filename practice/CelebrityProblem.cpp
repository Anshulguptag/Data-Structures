#include<bits/stdc++.h>
using namespace std;

list<int> *adj = new list<int>[100];

void Insert(int x,int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

int FindCeleb()
{
   for(int i=(int)'A';i!=(int)'G';i++)
    {
        if(*adj[i].begin()==0)
            return i;
    }
    return -1;
}
int main()
{
    Insert((int)'A',(int)'B');
    Insert((int)'B',(int)'C');
    Insert((int)'C',(int)'D');
    Insert((int)'A',(int)'C');
    Insert((int)'A',(int)'F');
    Insert((int)'E',0);

    if(FindCeleb()!=-1)
        cout<<(char)FindCeleb()<<" knows nobody";
    else
        cout<<"No Celebrity";

}
