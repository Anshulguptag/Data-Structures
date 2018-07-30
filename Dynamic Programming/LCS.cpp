 #include<bits/stdc++.h>

 using namespace std;

 int LCS(string str1,string str2, int **lcs,int M,int N)
 {
     int i,j;

     for(i=1;i<M+1;i++)
     {
         for(j=1;j<N+1;j++)
         {
             if(str1[i-1]==str2[j-1])
                lcs[i][j] = lcs[i-1][j-1]+1;
             else
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
         }
     }
     return (lcs[M][N]);
 }


 int main()
 {
     string str1 = "AGGTAB";
     string str2 = "GXTXAYB";

     int M = str1.length();
     int N = str2.length();

     int **lcs = new int*[M+1];
     int i,j;
     for(i=0;i<M+1;i++)
        lcs[i] = new int[N+1];
     for(j=0;j<N+1;j++)
        lcs[0][j]=0;
     for(j=0;j<M+1;j++)
        lcs[j][0]=0;
     cout<<"LCS is: "<<LCS(str1,str2,lcs,M,N);
 }
