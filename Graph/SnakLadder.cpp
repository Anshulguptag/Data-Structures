#include<iostream>
#include<queue>
using namespace std;

struct queueEntry
{
    int v;
    int distance;
};

int getMinDicethrows(int N,int moves[])
{
    queue<queueEntry> q;
    bool *visited = new bool[N];
    for(int i=0;i<N;i++)
        visited[i] = false;
    visited[0] = true;
    queueEntry s = {0,0};
    q.push(s);
    queueEntry qe;
    while(!q.empty())
    {
        qe = q.front();
        if(qe.v==N-1)
            break;
        q.pop();
        for(int j=(qe.v+1);j<=(qe.v+6) && j<N; j++)
        {
            if(!visited[j])
            {
                queueEntry a;
                a.distance = (qe.distance+1);
                visited[j] = true;
                if(moves[j]!=-1)
                    a.v = moves[j];
                else
                    a.v = j;

                q.push(a);
            }
        }
    }
    return qe.distance;
}

int main()
{
    int N =30;
    int moves[N];
    for(int i=0;i<N;i++)
        moves[i] = -1;

    //Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    //Snake
    moves[18] = 6;
    moves[16] = 3;
    moves[20] = 8;
    moves[26] = 0;

    cout<<getMinDicethrows(N,moves);
}
