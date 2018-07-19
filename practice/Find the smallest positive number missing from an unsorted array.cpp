#include<bits/stdc++.h>
using namespace std;


list<int> *adj = new list<int>[20];

void Insert(int x)
{
    adj[x%17].push_back(x);
}

int main()
{
    int arr[] = {2, 3, -7, 6, 8, 1, -10, 15};
    int size = *(&arr+1)-arr;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>=0)
            Insert(arr[i]);
    }

    for(int i=1;i<size;i++)
    {
        list<int>::iterator i1;
        if(*adj[i].begin()==0)
        {
            cout<<"The smallest positive missing number is "<<i;
            break;
        }
    }

}
