#include<iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    int priority;
    Node* next;
    Node* prev;
};

Node* Insert(Node* head,int x,int priority)
{
    Node* node = new Node;
    node->data = x;
    node->priority = priority;
    if(head==NULL)
    {
        node->next = head;
        node->prev = head;
        head = node;
        return head;
    }
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    node->next = temp->next;
    node->prev = temp;
    temp->next = node;
    return head;
}
void getHighestPriority(Node* head)
{
    int max1 = head->priority;
    Node* temp;
    Node* temp1;
    temp = head;
    while(temp!=NULL)
    {
        if(temp->priority>max1)
            temp1 = temp;
        temp = temp->next;
    }
    cout<<"Highest Priority element: ";
    cout<<temp1->data<<" have priority "<<temp1->priority;
    cout<<"\n";
}
void Print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" "<<head->priority;
        cout<<"\n";
        head = head->next;
    }
    cout<<"\n";
}
Node* deleteHighestPriority(Node* head)
{
    int max1 = head->priority;
    Node* temp;
    Node* temp1;
    temp = head;
    while(temp!=NULL)
    {
        if(temp->priority>max1)
            temp1 = temp;
        temp = temp->next;
    }
    temp1->prev->next = temp1->next;
    delete temp1;
    return head;
}
int main()
{
    Node* head =NULL;
    int arr[] = {4,6,7,2,1};
    int pri[] = {rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1};
    int size = *(&arr+1)-arr;
    for(int i=0;i<size;i++)
    {
        head = Insert(head,arr[i],pri[i]);
    }
    Print(head);
    getHighestPriority(head);
    head =  deleteHighestPriority(head);
    Print(head);
}
