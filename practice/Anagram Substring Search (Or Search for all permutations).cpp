#include<bits/stdc++.h>
using namespace std;

void Anagram(string text,string pattern)
{
    map<char,int> m;
    for(int i=0;i<pattern.length();i++)
        m[pattern[i]] = m[pattern[i]] + 1;

    for(int j=0;j<(text.length()-pattern.length()+1);j++)
    {
        int flag = 0;
        map<char,int> m1;
        for(int k=j;k<pattern.length()+j;k++)
            m1[text[k]] = m1[text[k]] + 1;
        for(int k=j;k<pattern.length()+j;k++)
        {
            if(m[text[k]]!=m1[text[k]])
            {
                flag = 1;
                break;
            }
        }
        if(flag!=1)
            cout<<j<<" ";
    }
}

int main()
{
    Anagram("AAABABAA","AABA");
}
