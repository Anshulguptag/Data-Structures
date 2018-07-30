#include <iostream>
#include <list>
using namespace std;
int main ()
{
  list<int> mylist;
  for (int i=1; i<=5; ++i) mylist.push_back(i);

  list<int>::iterator it;
  cout << "List is:";
  for(it=mylist.begin();it!=mylist.end();it++)
      cout<<"-->"<<*it;
  cout<<"\nModified list is: ";
  list<int>::reverse_iterator rit;
  for (rit=mylist.rbegin(),it=mylist.begin(); rit!=mylist.rend(),it!=mylist.end(); ++rit,++it)
       {
           if(*rit==*it)
           {
               cout<<*it;
               break;
           }
           cout <<*it<<"-->"<< *rit<<"-->";
       }

  cout << '\n';

  return 0;
}
