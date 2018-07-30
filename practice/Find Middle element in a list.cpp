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
    while(temp->next != NULL)
        temp = temp->next;
    node->next =  temp->next;
    temp->next = node;
    return head;
}

int Middle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
  Node* head = NULL;
  head = Insert(head,4);
  head = Insert(head,2);
  head = Insert(head,3);
  head = Insert(head,5);
  head = Insert(head,9);
  head = Insert(head,1);
  head = Insert(head,10);

  cout<<Middle(head);
}
