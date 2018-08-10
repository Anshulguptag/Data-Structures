#include<bits/stdc++.h>
using namespace std;

int solve(int A) {
    if(A==4)
        return 2;
    int count1 = 1;
    for(int i=2;i<A/2;i++)
    {
        int flag =1;
        for(int j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                flag = 0;
                break;
            }
        }
        if(flag==1)
        {
            int n = A-i;
            int flag1 = 1;
            for(int j=2;j<=n/2;j++)
            {
                if(n%j==0)
                {
                    flag1 = 0;
                    break;
                }
            }
            if(flag1==1)
            {
                if((i+n)==A)
                    count1++;
                break;
            }
        }
    }
    return count1;
}

int main()
{
    cout<<solve(987564231);
}


/*
void solve(vector<int> &A, vector<int> &B) {
    vector<int> G(B.size());
    int m=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i;j<A.size();j++)
        {
            int max = A[j];
            for(int k=i;k<=j;k++)
            {
                if(A[k]>max)
                   max = A[k];
            }
            G[m] = max;
            m++;
        }
    }
    for(int i=0;i<6;i++)
        cout<<G[i];
}

int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(4);
    vector<int> B;
    B.push_back(1);
    B.push_back(2);
    B.push_back(3);
    B.push_back(4);
    B.push_back(5);
    B.push_back(6);

    solve(A,B);

}
*/
