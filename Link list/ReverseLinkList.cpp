#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* Insert(Node* head, int x, int pos)
{
    Node* node = new Node;
    node->data = x;
    if(head==NULL || pos==1)
    {
        node->next = head;
        head = node;
    }
    else{
        Node* temp = head;
        for(int i=1;i<pos-1;i++)
        {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }
    return head;
}

void Print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
    cout<<"\n";
}

Node* ReverseLinkList(Node* head)
{
    Node* prev=NULL;
    Node* current = head;
    Node* next ;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        if(next==NULL)
           break;
        current = next;
    }
    head = current;
    return head;
}
int main()
{
    Node* head = NULL;
    cout<<"How many elements to be inserted: ";
    int n,x,i,pos;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter the element that is insert: ";
        cin>>x;
        cout<<"Enter the position where the element is insert: ";
        cin>>pos;
        head = Insert(head, x, pos);
        Print(head);
    }
    cout<<"Reversed Linklist: ";
    head = ReverseLinkList(head);
    Print(head);
    return 0;
}
