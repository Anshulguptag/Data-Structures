#include<bits/stdc++.h>
using namespace std;

void arrayIndex(string pattern,int n,int len[])
{
   for(int i=0;i<n;i++)
        len[i] = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j && pattern[i]==pattern[j])
                len[i] = len[i] + 1;
        }
    }
}

void findPatterns(string dict[],string pattern,int size)
{
   int pLen = pattern.length();
   int len[pLen];
   arrayIndex(pattern,pLen,len);
    for(int i=0;i<size;i++)
    {
        int dLen[pLen];
        int count1 = 0;
        arrayIndex(dict[i],pLen,dLen);
        for(int j=0;j<pLen;j++)
            {
                if(dLen[j]==len[j])
                    count1++;
            }
        if(count1==3 && dict[i].length()==pLen)
            cout<<dict[i]<<" ";
    }

}

int main()
{
    string dict[] = {"abb", "abc", "xyz", "xyy"};
    int size = *(&dict+1)-dict;
    string pattern = "mno";
    findPatterns(dict,pattern,size);
}
