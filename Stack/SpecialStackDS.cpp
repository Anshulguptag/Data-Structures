#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int> s,s1;
    int arr[] ={18,19,29,15,16};
    int size = *(&arr+1)-arr;
    s.push(arr[0]);
    s1.push(arr[0]);
    int mini = s1.top();
    for(int i=1;i<size;i++)
    {
        if(arr[i]<s1.top())
        {
            s1.push(arr[i]);
            mini = arr[i];
        }
        else
            s1.push(mini);

        s.push(arr[i]);
    }
    while(!s.empty())
    {
        cout<<s1.top();
        s1.pop();
        s.pop();
    }
}
