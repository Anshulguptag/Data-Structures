#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v;
    for (int i=0;i<10;i++)
    {
        v.push_back(rand()%100);
    }
    for(vector<int>::iterator itr=v.begin();itr!=v.end();itr++)
    {
        cout<<*itr<<endl;
    }
    cout<<"set copy......"<<endl;
    set<int> s;
    copy(v.begin(),v.end(),inserter(s,s.begin()));

    for(set<int>::iterator itr=s.begin();itr!=s.end();itr++)
    {
        cout<<*itr<<endl;
    }
    cout<<"Find element 41: "<<endl;
    cout<<*(find(v.begin(),v.end(),41))<<endl;
    cout<<"Sorting vector: "<<endl;
    sort(v.begin(),v.end());
    for(vector<int>::iterator itr=v.begin();itr!=v.end();itr++)
    {
        cout<<*itr<<endl;
    }

    return 0;
}
