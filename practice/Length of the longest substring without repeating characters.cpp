#include<bits/stdc++.h>
using namespace std;

int LongestSubstring(string str)
{
    int maxLen = 0;
    for(int i=0;i<str.length();i++)
    {
        map<char,int> m;
        int k=i;
        int count=0;
        while(k<str.length())
        {
            if(m[str[k]]!=0)
                break;
            m[str[k]] = m[str[k]]+1;
            count++;
            k++;
        }
        if(maxLen<count)
            maxLen = count;
    }
    return maxLen;
}

int main()
{
    string str = "ABDEFGABEF";
    cout<<"The input string is "<<str;
    cout<<"\nThe length of the longest non-repeating character substring is "<<LongestSubstring(str);
}
