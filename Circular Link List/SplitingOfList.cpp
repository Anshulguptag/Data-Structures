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
            temp = temp->next;
        }
        node->next=temp->next;
        temp->next = node;
    }
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

int getsize(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    int count = 0;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        count++;
        if(slow==fast)
        {
            break;
        }

    }
    return count;
}

void SplitList(Node* head)
{
    int size1 = getsize(head);
    Node* temp = head;
    Node* temp1 = head;
    Node* temp2 = temp1->next;
    Node* slow = head;
    Node* fast = head;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            break;
        }
        temp =temp->next;
    }

    for (int i=1;i<size1/2; i++)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = head;
    temp->next = temp2;
    cout<<"\nAfter Splitting the list into two halves\n";
    cout<<"List 1: ";
    Print(head);
    cout<<"\nList 2: ";
    Print(temp2);


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
    SplitList(head);
    return 0;
}
