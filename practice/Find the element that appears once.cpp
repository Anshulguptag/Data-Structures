#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    int arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
    int n = *(&arr+1)-arr;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
        sum  = sum + arr[i];
    }
    set<int>::iterator i1;
    int sum1 = 0;
    for(i1=s.begin();i1!=s.end();i1++)
        sum1  = sum1 + *i1;
    cout<<(3*(sum1)-sum)/2;
}
