#include<bits/stdc++.h>
using namespace std;

map<int, int> Insert(map<int, int> m,int size,int arr[])
{
    for(int i=0;i<size;i++)
        m[arr[i]] = 1 ;
    return m;
}
void findCommon(int arr[],map<int, int> m1, map<int, int> m2, map<int, int> m3,int iterations)
{
    for(int i=0;i<iterations;i++)
    {
        if(m1[arr[i]]!=0 && m2[arr[i]]!=0 && m3[arr[i]]!=0)
            cout<<arr[i]<<" ";
    }
}
int main()
{
    int ar1[] = {1, 5, 5};
    int ar2[] = {3, 4, 5, 5, 10};
    int ar3[] = {5, 5, 10, 20};
    int s1 = *(&ar1+1)-ar1;
    int s2 = *(&ar2+1)-ar2;
    int s3 = *(&ar3+1)-ar3;
    map<int, int> m1,m2,m3;
    m1 = Insert(m1,s1,ar1);
    m2 = Insert(m2,s2,ar2);
    m3 = Insert(m3,s3,ar3);
    int iterations = min(min(s1,s2),s3);
    if(iterations==s1)
        findCommon(ar1,m1,m2,m3,iterations);
    else if(iterations==s2)
        findCommon(ar2,m1,m2,m3,iterations);
    else if(iterations==s3)
        findCommon(ar3,m1,m2,m3,iterations);


}
