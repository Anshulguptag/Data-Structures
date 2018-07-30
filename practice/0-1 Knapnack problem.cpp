#include<bits/stdc++.h>
using namespace std;

/*

if(wt[i]>w)
    V[i,w] = V[i-1,w]
else if(wt[i]<=w)
    V[i,w] = max(V[i-1,w], val[i] + V[i-1,w-wt[i]])


 item i     1    2   3   4
 value val 100  20  60  40
 weight wt  3    2   4   1

 W=5

V[i,w] w=0  1    2    3    4    5
 i=0    0   0    0    0    0    0
  1     0   0    0   100  100  100
  2     0   0    20  100  100  120
  3     0   0    20  100  100  120
  4     0   40   40  100  140  140

*/


int knapsack(int W,int wt[],int val[],int n)
{
    int i, w;
    int V[n+1][W+1];
    for(i=0;i<=n;i++)
    {
        for(w = 0;w<=W;w++)
        {
            if(i==0 || w==0)
                V[i][w] = 0;
            else if(wt[i-1]>w)
                V[i][w] = V[i-1][w];
            else if(wt[i-1]<=w)
                V[i][w] = max(V[i-1][w], val[i-1]+V[i-1][w-wt[i-1]]);
        }
    }
    return V[n][W];
}


int main()
{
    int value[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = *(&value+1)-value;
    cout<<knapsack(W,wt,value,n);
}
