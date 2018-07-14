#include<iostream>
#include<list>
using namespace std;

list<int> *adj = new list<int>[30];

int hashfunction(int x,int size)
{
    return (x%size);
}

void Insert(int x,int size)
{
    adj[hashfunction(x,size)].push_back(x);
}

bool isSubset(int arr[],int arr2[],int size,int size1)
{
    int count = 0;
    list<int>::iterator i;
    for(int j=0;j<size1;j++)
        {
            int key = hashfunction(arr2[j],size);
            for(i=adj[key].begin();i!=adj[key].end();i++)
            {
                if(*i==arr2[j])
                {
                    count++;
                    break;
                }
            }
        }
    if(count==size1)
        return true;
    else
        return false;

}
int main()
{
    int arr[] = {11,1,13,21,3,7};
    int arr2[] = {11,3,7,1};
    int size = *(&arr+1)-arr;
    int size1 = *(&arr2+1)-arr2;
    for(int i=0;i<size;i++)
    {
        Insert(arr[i],size);
    }
    /*
    for(int j=0;j<size;j++)
    {
        cout<<"["<<j<<"]";
        for(i=adj[j].begin();i!=adj[j].end();i++)
            cout<<"-"<<*i;
        cout<<"\n";
    }
    */
    if(isSubset(arr,arr2,size,size1))
        cout<<"arr2 is a subset of arr";
    else
        cout<<"arr2 is not a subset of arr";

}
