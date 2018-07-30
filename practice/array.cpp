#include<bits/stdc++.h>
using namespace std;

double sum(vector<int> A,int start,int end)
{
    double sum = 0;
    for(int i=start;i<end;i++)
    {
        if(A[i]>=0)
            sum = sum+A[i];
    }
    return sum;
}

vector<int> maxset(vector<int> &A) {
    int i;
    vector<int> temp;
    for(i=0;i<A.size();i++)
    {
        if(A[i]<0)
            break;
    }
    if(i==0)
    {
       for(int j=i+1;j<A.size();j++)
            if(A[j]>=0)
                temp.push_back(A[j]);
    }
    else if(i==A.size()-1)
    {
       for(int j=0;j<A.size()-1;j++)
            if(A[j]>=0)
                temp.push_back(A[j]);
    }
    else
    {
       if(sum(A,0,i)>sum(A,i+1,A.size()))
        {
            for(int j=0;j<i;j++)
                if(A[j]>=0)
                    temp.push_back(A[j]);
        }
    else if(sum(A,0,i)<sum(A,i+1,A.size()))
        {
            for(int j=i+1;j<A.size();j++)
                if(A[j]>=0)
                    temp.push_back(A[j]);
        }
    else
        {
            vector<int> temp1;
            vector<int> temp2;
            for(int j=0;j<i;j++)
                temp1.push_back(A[j]);
            for(int j=i+1;j<A.size();j++)
                temp2.push_back(A[j]);
            if(temp1.size()>=temp2.size())
            {
                for(int j=0;j<i;j++)
                    if(temp1[j]>=0)
                        temp.push_back(temp1[j]);
            }
            else if(temp1.size()<temp2.size())
            {
                for(int j=i+1;j<A.size();j++)
                    if(temp2[j]>=0)
                        temp.push_back(temp2[j]);
            }
            temp1.clear();
            temp2.clear();
        }
    }

    return temp;
}

int main()
{
    int arr[] = {336465782, -278722862, -2145174067, 1101513929, 1315634022, -1369133069, 1059961393, 628175011, -1131176229, -859484421};
    vector<int> A;
    for(int i=0;i<10;i++)
        A.push_back(arr[i]);
    vector<int> max1 = maxset(A);
    for(int i=0;i<max1.size();i++)
        cout<<max1[i]<<" ";
}
