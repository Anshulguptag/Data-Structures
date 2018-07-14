#include<iostream>
#include<list>
using namespace std;

list<int> *l = new list<int>[20];

int hashfunction(int x,int size)
{
    return x%size;
}
void Insert(int x,int size)
{
    l[hashfunction(x,size)].push_back(x);
}
bool findItem(list<int> adj,int pair2)
{
    list<int>::iterator i1;
    for(i1=adj.begin();i1!=adj.end();i1++)
        if(*i1==pair2)
        {
            return true;
        }
    return false;
}
void findPairs(int sum,int arr[],int size)
{
    for(int j=0;j<size;j++)
    {
        int pair2 = sum - arr[j];
        if(pair2>0)
            if(findItem(l[hashfunction(pair2,size)],pair2))
            {
                cout<<"Pair with given sum "<<sum<<" is ("<<arr[j]<<", "<<pair2<<")";
                return;
            }
    }
    cout<<"No pair is found";
}
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int size = *(&arr+1)-arr;
    for(int i=0;i<size;i++)
        Insert(arr[i],size);

    findPairs(55,arr,size);
}
