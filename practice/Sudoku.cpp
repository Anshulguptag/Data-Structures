#include<bits/stdc++.h>
using namespace std;

int N =9;

bool getEmpty(int sudoku[9][9],int &row,int &col)
{
    for(row=0;row<N;row++)
        for(col=0;col<N;col++)
            if(sudoku[row][col]==0)
                return true;
    return false;
}
bool UsedInRow(int sudoku[9][9],int row,int num)
{
    for(int i=0;i<9;i++)
        if(sudoku[row][i]==num)
            return false;
    return true;
}
bool UsedInCol(int sudoku[9][9],int col,int num)
{
    for(int i=0;i<9;i++)
        if(sudoku[i][col]==num)
            return false;
    return true;
}
bool UsedInGrid(int sudoku[9][9],int startrow,int startcol,int num)
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(sudoku[i+startrow][j+startcol]==num)
                return false;
    return true;
}
bool isSafe(int sudoku[9][9],int row,int col,int num)
{
    return UsedInRow(sudoku,row,num) && UsedInCol(sudoku,col,num) && UsedInGrid(sudoku,row-row%3,col-col%3,num);
}
bool fillsudoku(int sudoku[9][9])
{
    int row,col;
    if(!getEmpty(sudoku,row,col))
        return true;
    cout<<row<<" "<<col<<" ";
    for(int i=1;i<=9;i++)
    {
        if(isSafe(sudoku,row,col,i))
        {
            sudoku[row][col] = i;
            if(fillsudoku(sudoku))
                return true;
            sudoku[row][col] = 0;
        }
    }
    cout<<"\n---\n";
    cout<<row<<" "<<col<<" ";
    return false;
}

int main()
{
    int sudoku[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    fillsudoku(sudoku);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(j==0)
                cout<<"|";
            cout<<sudoku[i][j]<<" ";
            if(j==2 || j==5 || j==8)
                cout<<"|";

        }
        cout<<"\n";
    }
}
