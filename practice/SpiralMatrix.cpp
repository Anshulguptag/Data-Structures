#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4][4] = {{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}
                    };
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }

    /*
    for(int i=0;i<4;i++)
        cout<<arr[0][i]<<" ";
    for(int i=1;i<4;i++)
        cout<<arr[i][3]<<" ";
    for(int i=1;i<4;i++)
        cout<<arr[3][3-i]<<" ";
    for(int i=0;i<3;i++)
        cout<<arr[1][i]<<" ";
    */
    int k=0;
    int l=0;
    int m=4;
    int n=4;
    while(k<m && l<n)
    {
        for(int i=l;i<n;i++)
            cout<<arr[k][i]<<" ";
        k++;
        for(int i=k;i<m;i++)
            cout<<arr[i][n-1]<<" ";
        n--;
        if(k<m)
        {
            for(int i=n-1;i>=1;i--)
                cout<<arr[m-1][i]<<" ";
            m--;
        }
        if(l<n)
        {
            for(int i=m-1;i>=k;i--)
                cout<<arr[i][l]<<" ";
            l++;
        }
    }

}
