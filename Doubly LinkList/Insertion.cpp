#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node* prev;
};

Node* Insert(Node* head, int x)
{
    Node* node = new Node;
    node->data = x;
    if(head==NULL)
    {
        node->next = head;
        node->prev = NULL;
        head = node;
    }
    else
    {
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        node->prev = temp;
        node->next = temp->next;
        temp->next = node;
    }
    return head;
}

void Print(Node* head)
{
    cout<<"NULL<-";
    while(head!=NULL)
    {
        cout<<head->data;
        if(head->next!=NULL)
        {
            cout<<"<=>";
        }
        head=head->next;
    }
    cout<<"->NULL";
    cout<<"\n";
}

int main()
{
    Node* head = NULL;
    cout<<"Enter the number of elements: ";
    int x,n,i;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Enter the element that you want to insert: ";
        cin>>x;
        head = Insert(head, x);
        Print(head);
    }
    return 0;
}
