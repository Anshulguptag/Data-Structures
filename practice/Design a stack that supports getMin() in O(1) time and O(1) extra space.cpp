#include<bits/stdc++.h>
using namespace std;

stack<int> s;

void getMin()
{
    stack<int> s1;
    int mini = s.top();

    while(!s.empty())
    {

        if(s.top()<mini)
           {
               mini = s.top();
           }
        s1.push(s.top());

        s.pop();
    }
    cout<<mini;
    while(!s1.empty())
    {
        s.push(s1.top());
        s1.pop();
    }
}

int main()
{
    s.push(18);
    s.push(19);
    s.push(29);
    s.push(15);
    s.push(16);

    getMin();

    s.pop();
    s.pop();

    getMin();
}
