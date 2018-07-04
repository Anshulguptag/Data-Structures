#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int> s;
    int arr[] = {4,2,3,1};
    int size = *(&arr+1)-arr;
    int max = -1;
    for(int i=0;i<size;i++)
    {
        s.push(arr[i]);
    }
    int x = s.top();
    for(int i=0;i<size;i++)
    {
        if(x<max)
            cout<<s.top()<<"--->"<<max;
        else
            cout<<s.top()<<"--->"<<"-1";
        if(s.top()>max)
            max=s.top();
        s.pop();
        x = s.top();
        cout<<"\n";
    }
}
