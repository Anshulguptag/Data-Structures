//set store the data in the form of tree(BST)
#include<iostream>
#include<set>

using namespace std;

int main()
{
    set<int> s;

    for(int i=0;i<10;i++)
    {
        s.insert(10-i);
    }

    set<int>::iterator it;
    it = s.find(6);

    //s,erase(it); X

    for(set<int>::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<endl;
    }
    return 0;
}
