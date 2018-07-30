#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* Insert(Node* head,int x)
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
        temp = temp->next;
    node->next = temp->next;
    temp->next = node;

    return head;
}

Node* Delete(Node* head)
{
    if(head == NULL)
        return head;
    Node* temp = head;
    if(head->next==NULL)
    {
        head = NULL;
        return head;
    }
    while(temp->next->next!=NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
    return head;
}

Node* top(Node* head)
{
    if(head==NULL)
        return head;
    Node* temp = head;
    while(temp->next!=NULL)
        temp = temp->next;

    return temp;
}

int main()
{
    int arr[] = {12,14,3,5,6,20};
    int n = 6;
    Node* head =NULL;
    for(int i=0;i<n;i++)
        head = Insert(head,arr[i]);
    while(head!=NULL)
    {
      cout<<top(head)->data<<" ";
      head = Delete(head);
    }
}
