#include<bits/stdc++.h>
using namespace std;

int main()
{
    int M,N;
    M = N = 4;
    int arr[M][N]= {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
            if(i<=j)
            {
              int temp = arr[i][j];
              arr[i][j] = arr[j][i];
              arr[j][i] = temp;
            }
    }
    for(int i=0;i<M/2;i++)
    {
        for(int j=0;j<N;j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[M-1-i][j];
            arr[M-1-i][j] = temp;
        }
    }
    cout<<"\n";
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }

}
