#include<iostream>
using namespace std;

struct Node{
   int data;
   struct Node* next;
};

Node* Insert(Node* head, int x)
{
    Node* node = new Node;
    node->data = x;
    if(head==NULL)
    {
        node->next = head;
        head = node;
    }
    else{
        Node* temp = head;
        while(temp->next!=NULL)
        {
            if(temp->next->data>x)
            {
                break;
            }
            temp = temp->next;
        }
        node->next=temp->next;
        temp->next = node;
    }
    return head;
}

Node* makecircular(Node* head)
{
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    return head;
}

void Print(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(slow && fast && fast->next)
    {
        cout<<slow->data;
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            cout<<"->"<<slow->data;
            break;
        }

        cout<<"->";
    }
}

int main()
{
    Node* head = NULL;
    cout<<"Enter the number of elements: ";
    int n,x,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter the value that is insert: ";
        cin>>x;
        head = Insert(head,x);
    }
    head = makecircular(head);
    cout<<"\nCircular Link list: ";
    Print(head);
    return 0;
}
