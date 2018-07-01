//In Multimap we can insert duplicate values but this is not possible in map
#include<iostream>
#include<map>
using namespace std;

int main()
{
    pair<char,int> x;
    multimap<char, int> m;

    for(char ch='a';ch<='z';ch++)
    {
        x.first=ch;
        x.second=(int)ch;

        m.insert(x);
    }

    multimap<char, int>::iterator itr=m.begin();

    for(itr=m.begin();itr!=m.end();itr++)
    {

        cout<<(*itr).first<<" "<<(*itr).second<<endl;
    }

    x.first='j';
    x.second=1000;
    m.insert(x);
    for(itr=m.begin();itr!=m.end();itr++)
    {

        cout<<(*itr).first<<" "<<(*itr).second<<endl;
    }

    cout<<"Finding a value: "<<endl;
    itr = m.find('j');
    cout<<(*itr).second<<endl; //using iterator
    /* Not possible in multimap
    cout<<m['j']; //using indexing
    */
    return 0;
}
