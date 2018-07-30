#include<bits/stdc++.h>
using namespace std;

string Encoded(string input)
{
    string output = "";
    map<char, int> m;
    for(int i=0;i<input.length();i++)
    {
        m[input[i]]=m[input[i]]+1;;
    }
    map<char, int>::iterator itr=m.begin();

    for(int i=0;i<input.length();i++)
    {
        if(input[i]!=input[i+1])
            output = output + input[i] + char(m[input[i]]+'0');
    }
    return output;
}

int main()
{
    cout<<Encoded("wwwwaaadexxxxxx");
}
