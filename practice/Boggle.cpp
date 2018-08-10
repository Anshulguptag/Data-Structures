#include<bits/stdc++.h>
using namespace std;
void makeVisited(bool visited[3][3])
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            visited[i][j] = false;
}

int main()
{
    int boggle[3][3] = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};
    bool visited[3][3];
    makeVisited(visited);

}
