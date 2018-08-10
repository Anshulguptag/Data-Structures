#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};
    int n = *(&arr+1)-arr;
    set<int> s;
    for(int i=0;i<n;i++)
        s.insert(arr[i]);
    map<int,int> m;
    set<int>::iterator i1;
    int k=0;
    for(i1=s.begin();i1!=s.end();i1++)
    {
        for(int i=0;i<n;i++)
        {
            if(*i1==arr[i])
                m[k] = m[k]+1;
        }
        k++;
    }
    cout<<"The two non-repeating elements are: ";
    int i=0;
    for(i1=s.begin();i1!=s.end();i1++)
    {
        if(m[i]==1)
           cout<<*i1<<" ";
        i++;
    }

}
