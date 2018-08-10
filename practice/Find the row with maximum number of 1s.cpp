#include<bits/stdc++.h>
using namespace std;
int R=4;
int C=4;
int rowIndex(bool mat[4][4])
{
   int count1=0,index;

    for(int i=0;i<R;i++)
    {
        int count=0;
        for(int j=0;j<C;j++)
        {
            if(mat[i][j]==1)
                count++;
        }
        if(count>count1)
        {
            count1 = count;
            index = i;
        }
    }
    cout<<index;
}
int main()
{
    bool mat[4][4] = { {0, 0, 0, 1},
                       {0, 1, 1, 1},
                       {1, 1, 1, 1},
                       {0, 0, 0, 0}};
    rowIndex(mat);

}
