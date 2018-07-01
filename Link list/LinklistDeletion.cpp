#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

//Insert an element
Node* Insert(Node* head, int x, int pos)
{
    Node* node=new Node;
    node->data = x;
    if(head==NULL || pos==1)
    {
      node->next = head;
      head =  node;
    }
    else{
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

//Print List
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

//Delete an element
Node* Delete(Node* head, int x)
{
    Node* temp;
    Node* temp1=head;
    Node* temp2=temp1->next;
    if(head->data==x)
    {
        temp = head;
        head = head->next;
        cout<<"Element Delete Successfully! ";
        cout<<"\n";
        delete temp;
        return head;
    }
    while(temp2!=NULL)
    {
        if(temp2->data==x)
        {
            temp = temp2;
            delete temp2;
            temp1->next = temp->next;
            cout<<"Element Delete Successfully! ";
            cout<<"\n";
            delete temp;
            return head;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }


}

//Main Function
int main()
{
    Node* head = NULL;
    cout<<"Enter the number of elements to be inserted: ";
    int n,i,x,pos;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter the value to be inserted: ";
        cin>>x;
        cout<<"Enter the position where you want to insert: ";
        cin>>pos;
        head = Insert(head, x, pos);
        Print(head);
        cout<<"Do you want to delete any element: ";
        char ch;
        cin>>ch;
        if(ch=='y')
        {
            cout<<"Enter the Element to be deleted: ";
            cin>>x;
            head = Delete(head, x);
            Print(head);
        }
    }
    return 0;
}
