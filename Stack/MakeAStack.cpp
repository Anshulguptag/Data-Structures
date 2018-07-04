#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* Push(Node* head, int x)
{
    Node* node = new Node;
    node->data = x;
    node->next = head;
    head = node;
}

void Print(Node* head)
{
    if(head == NULL)
    {
        cout<<"Top-->-1";
    }
    else
    {
       cout<<"Top-->["<<head->data<<"] ";
        head = head->next;
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<"\n";
    }

}

Node* Pop(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" is popped";
        head = head->next;
        cout<<"\n";
        Print(head);
    }
    return head;
}
int main()
{
    Node* head = NULL;
    cout<<"Enter number of elements that you want to insert into a stack: ";
    int n,x,i;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Enter the element: ";
        cin>>x;
        head = Push(head, x);
        Print(head);
    }
    cout<<"\nPopping the stack\n";
    head = Pop(head);
    return 0;
}

