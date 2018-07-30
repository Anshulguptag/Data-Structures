#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* Insert(Node* head,int data)
{
    Node* node = new Node;
    node->data = data;
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

bool isCircular(Node* head)
{
    Node* slow =head;
    Node* fast = head;
    while(fast!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}
Node* makeCircular(Node* head)
{
    Node* temp = head;
    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = head;
    return head;
}
int main()
{
    Node* head = NULL;
    int arr[] = {10,12,14,16};
    int size = *(&arr+1)-arr;
    for(int i=0;i<size;i++)
        head = Insert(head,arr[i]);
    cout<<isCircular(head);
    head = makeCircular(head);
    cout<<isCircular(head);
}
