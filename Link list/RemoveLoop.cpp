#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

Node* Insert(Node* head, int x);
void Print(Node* head);
Node* LoopMaker(Node* head);
int LoopDetector(Node* head);
Node* LoopRemover(Node* head, int size);
int getsize(Node* head);
int main()
{
    Node* head = NULL;
    cout<<"How many Numbers: ";
    int n,i,x;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cout<<"Enter a number to be insert: ";
        cin>>x;
        head = Insert(head, x);
        Print(head);
    }
    int size = getsize(head);
    cout<<"List without Loop ";
    LoopDetector(head);
    head = LoopMaker(head);
    cout<<"When Loop is added ";
    LoopDetector(head);
    LoopRemover(head, size);
    cout<<"When Loop is Removed ";
    LoopDetector(head);
    return 0;
}

Node* Insert(Node* head, int x)
{
    Node* node = new Node;
    node->data = x;
    if(head==NULL)
    {
        node->next = head;
        head = node;
    }
    else
    {
        Node* temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node->next = temp->next;
        temp->next = node;

    }
    return head;
}

Node* LoopMaker(Node* head)
{
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = head->next->next;
    return head;
}
void Print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<"\n";
}
int getsize(Node* head)
{
    int count=0;

    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}
Node* LoopRemover(Node* head, int size)
{
    Node* temp = head;
    for(int i=0; i<size-1; i++)
    {
        temp=temp->next;
    }
    temp->next = NULL;
     return head;
}
int LoopDetector(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            cout<<"Yes Loop is find :)\n";
            cout<<"Loop at: "<<slow->data<<"\n";
            return 0;
        }
    }
    Print(head);
}


