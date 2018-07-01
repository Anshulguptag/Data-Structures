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
    int count = 0;
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
        count++;
    }
    cout<<"NULL";
    cout<<"\nLength of list: "<<count;
    cout<<"\n";
}
int main()
{
    Node* head = NULL;
    cout<<"Enter How many elements to be insert: ";
    int x,i,n,pos;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter the element to be insert: ";
        cin>>x;
        cout<<"Enter the position where you want to insert element: ";
        cin>>pos;
        head=Insert(head,x,pos);
        Print(head);
    }
    return 0;
}
