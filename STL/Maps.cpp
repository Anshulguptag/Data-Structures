#include<iostream>
#include<map>
using namespace std;

int main()
{
    pair<char,int> x;
    map<char, int> m;

    for(char ch='a';ch<='z';ch++)
    {
        x.first=ch;
        x.second=(int)ch;

        m.insert(x);
    }

    map<char, int>::iterator itr=m.begin();

    for(itr=m.begin();itr!=m.end();itr++)
    {

        cout<<(*itr).first<<" "<<(*itr).second<<endl;
    }

    cout<<"Finding a value: "<<endl;
    itr = m.find('j');
    cout<<(*itr).second<<endl; //using iterator
    cout<<m['j']; //using indexing
    return 0;
}
