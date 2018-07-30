#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "aabbccd";
    map<char,int> Map;
    for(int i=0;i<str.length();i++)
    {
        map<char, int>::iterator it = Map.find(str[i]);
        if (it != Map.end())
            it->second = 1;
        Map.insert(pair <char,int> (str[i],0));
    }
    map<char, int>::iterator itr=Map.begin();
    for(itr=Map.begin();itr!=Map.end();itr++)
    {
        if((*itr).second==0)
        {
           cout<<"First non-repeating element is : "<<(*itr).first;
           break;
        }
    }
}

