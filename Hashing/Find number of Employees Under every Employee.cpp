#include<iostream>
#include<list>
using namespace std;

list<int> *adj = new list<int>[6];

int hashfunction(int i,int size)
{
    return i%size;
}
void Insert(int x,int y,int size)
{
    adj[hashfunction(y,size)].push_back(x);
}

int getIndex(char ch,char arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(arr[i]==ch)
            return i;
    }
}
void getEmployees(char ch,char arr[],int size,int *count)
{
    list<int>::iterator i1;

    for(i1=adj[getIndex(ch,arr,size)].begin();i1!=adj[getIndex(ch,arr,size)].end();i1++)
        {
            *count = *count+1;
            getEmployees(arr[*i1],arr,size,count);
        }

}
int main()
{
    char arr[] = {'A','B','C','D','E','F'};
    int size = *(&arr+1)-arr;

    Insert(getIndex('A',arr,size),getIndex('C',arr,size),size);
    Insert(getIndex('B',arr,size),getIndex('C',arr,size),size);
    Insert(getIndex('C',arr,size),getIndex('F',arr,size),size);
    Insert(getIndex('D',arr,size),getIndex('E',arr,size),size);
    Insert(getIndex('E',arr,size),getIndex('F',arr,size),size);

    /*
    list<int>::iterator i1;
    for(int j=0;j<size;j++)
    {
        cout<<"["<<arr[j]<<"]";
        for(i1=adj[j].begin();i1!=adj[j].end();i1++)
        {
            cout<<"-"<<arr[*i1];
        }
        cout<<"\n";
    }
    */
    cout<<"result = {";
    for(int j=0;j<size;j++)
    {
        int count = 0;
        getEmployees(arr[j],arr,size,&count);
        cout<<arr[j]<<"="<<count<<", ";
    }
    cout<<"}";
}
