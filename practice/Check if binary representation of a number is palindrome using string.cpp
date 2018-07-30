#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]!=str[str.length()-1-i])
            return false;
    }
    return true;
}

string DecimalToBinary(int n)
{
    string output = "";
    while(n!=0)
    {
        int rem = n%2;
        output = output + char((char)rem + '0');
        n = n/2;
    }
    return output;
}

int main()
{
    cout<<isPalindrome(DecimalToBinary(21));
}
