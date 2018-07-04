#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* Push(Node* head, int x)
{
    Node* node = new Node;
    node->data = x;
    if(head==NULL)
    {
        node->next = head;
        head = node;
        return head;
    }
    Node* temp = head;
    while(temp->next!=NULL)
        temp=temp->next;

    node->next=temp->next;
    temp->next = node;

    return head;
}

void Print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int Greatest(Node* head, int x)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data==x)
            {
                break;
            }
        temp = temp->next;
    }
    temp = temp->next;
    while(temp!=NULL)
    {
        if(temp->data>x)
            return temp->data;
        temp = temp->next;
    }
    return -1;
}
int main()
{
    Node* head = NULL;
    int arr[] = {4, 5, 2, 25};
    int size = *(&arr+1)-arr;
    for(int i=0;i<size;i++)
    {
        head = Push(head,arr[i]);
    }
    Print(head);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"---->"<<Greatest(head,arr[i]);
        cout<<"\n";
    }
}
