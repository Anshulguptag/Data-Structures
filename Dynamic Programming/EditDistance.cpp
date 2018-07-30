#include<bits/stdc++.h>
using namespace std;

int EditDistance(string str1,string str2,int M,int N,int **ED)
{
    int i,j;
    for(i=1;i<M+1;i++)
    {
        for(j=1;j<N+1;j++)
        {
            if(str1[i-1]==str2[j-1])
               ED[i][j] = ED[i-1][j-1];
            else
                ED[i][j] = min(min(ED[i-1][j], //Remove
                                   ED[i][j-1]), //Insert
                               ED[i-1][j-1] //Replace
                               )+1;
        }
    }
    return ED[M][N];
}

int main()
{
    string str1 = "CART";
    string str2 = "MARCH";
    int M = str1.length();
    int N = str2.length();

    int **ED = new int*[M+1];
    int i,j;
    for(i=0;i<M+1;i++)
        ED[i] = new int[N+1];
    for(j=0;j<M+1;j++)
       ED[j][0] = j;
    for(j=0;j<N+1;j++)
       ED[0][j] = j;

    cout<<EditDistance(str1,str2,M,N,ED);
}
