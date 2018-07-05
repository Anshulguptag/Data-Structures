#include<iostream>
using namespace std;

struct Stack
{
    int data;
    Stack* next;
};

Stack* Push(Stack* top, int x)
{
    Stack* stack = new Stack;
    stack->data = x;
    stack->next = top;
    top = stack;

    return stack;
}

Stack* Pop(Stack* top)
{
    Stack* temp  = top;
    top = top->next;
    delete temp;

    return top;
}

void Print(Stack* top)
{
    while(top!=NULL)
    {
        cout<<top->data<<" ";
        top = Pop(top);
    }
}

Stack* Reverse(Stack* top)
{
    if(top==NULL)
        return top ;
    int temp = top->data;
    top = Pop(top);
    Reverse(top);
    cout<<temp;
}
int main()
{
    Stack* top = NULL;
    int arr[] = {4,3,2,1};
    int size = *(&arr+1)-arr;
    for(int i=0;i<size;i++)
    {
        top = Push(top, arr[i]);
    }
    Print(top);
    Reverse(top);

}
