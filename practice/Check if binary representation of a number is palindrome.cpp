#include<bits/stdc++.h>
using namespace std;

int length(int n)
{
    int count = 0;
    while(n!=0)
    {
        n = n/10;
        count++;
    }
    return count;
}

bool checkPalindrome(int n)
{
    int len = length(n);
    int sum = 0;
    for(int i=0;i<len;i++)
    {
        int rem = n%10;
        if(len%2!=0)
        {
           if(i==len/2)
              rem = 0;
           if(i>(len/2))
              rem = -1*rem;
        }
        else
        {
           if(i>(len/2)-1)
              rem = -1*rem;
        }
        sum = sum + rem;
        n = n/10;
    }
    if(sum==0)
        return true;
    else
        return false;
}

int main()
{
    if(checkPalindrome(11011)==1)
        cout<<"Palindrome";
    else
        cout<<"Not Palindrome";
}
