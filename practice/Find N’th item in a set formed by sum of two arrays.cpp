#include<bits/stdc++.h>
using namespace std;

int FindElement(int arr1[],int arr2[],int n1,int n2,int N)
{
    set<int> s;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
            s.insert(arr1[i]+arr2[j]);
    }
    if(s.size()<N)
        return -1;
    set<int>::iterator i1=s.begin();
    int c;
    for(int i=0;i<N;i++)
    {
        c = *i1;
        i1++;
    }

    return(c);

}

int main()
{
    int arr1[] = {1, 2};
    int arr2[] = {3, 4};
    int n1 =*(&arr1+1)-arr1;
    int n2 =*(&arr2+1)-arr2;
    cout<<FindElement(arr1,arr2,n1,n2,3);
}
