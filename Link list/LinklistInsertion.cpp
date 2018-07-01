#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

Node* Insert(Node* head, int x, int pos);
void Print(Node* head);

int main()
{
    Node* head = NULL;
    cout<<"How many Numbers: ";
    int n,i,x,pos;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cout<<"Enter a number to be insert: ";
        cin>>x;
        cout<<"Enter the position where you want to insert: ";
        cin>>pos;
        head = Insert(head, x, pos);
        Print(head);
    }
    return 0;
}

Node* Insert(Node* head, int x, int pos)
{
    Node* node = new Node;
    node->data = x;
    if(head==NULL || pos==1)
    {
        node->next = head;
        head = node;
    }
    else
    {
        Node* temp = head;
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
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
