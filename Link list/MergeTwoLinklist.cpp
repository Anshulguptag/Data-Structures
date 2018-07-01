#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

Node* Insert(Node* head, int x, int pos);
void Print(Node* head);
Node* Delete(Node* head, int x);
Node* Merge(Node* head1, Node* head2);

//Main Function
int main()
{
    Node* head = NULL;
    cout<<"Linlist 1: ";
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
    Node* head2 = NULL;
    cout<<"Linlist 2: ";
    cout<<"How many Numbers: ";
    cin>>n;
    for (i=0;i<n;i++)
    {
        cout<<"Enter a number to be insert: ";
        cin>>x;
        cout<<"Enter the position where you want to insert: ";
        cin>>pos;
        head2 = Insert(head2, x, pos);
        Print(head2);
    }
    Node* head3=Merge(head,head2);
    cout<<"After Merging both List: ";
    Print(head3);
    return 0;
}

//Delete Function
Node* Delete(Node* head, int x)
{
    if(head==NULL)
    {
        cout<<"List is Empty";
        return NULL;
    }
    Node* temp;
    Node* temp1=head;
    Node* temp2=temp1->next;
    if(head->data==x)
    {
        temp = head;
        head = head->next;
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
            delete temp;
            return head;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }


}

//Insert Function
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

//Print Function
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

//Merge function
Node* Merge(Node* head1, Node* head2)
{
    Node* head3 = NULL;
    int i=1;
    while(head1!=NULL && head2!=NULL )
    {
        Node* temp1 = head1;
        Node* temp2 = head2;
        int min1=head1->data,min2=head2->data;
        while(temp1!=NULL)
        {
            if(temp1->data<min1)
                min1=temp1->data;
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            if(temp2->data<min2)
                min2=temp2->data;
            temp2=temp2->next;
        }
        if(min1 < min2)
            {
             head3 = Insert(head3, min1, i);
             i++;
             head1 = Delete(head1,min1);
            }
        else
        {
            head3 = Insert(head3, min2, i);
             i++;
            head2 = Delete(head2,min2);
        }

    }
    while(head1!=NULL)
    {
      Node* temp1 = head1;
      int min1=head1->data;
      while(temp1!=NULL)
        {
            if(temp1->data<min1)
                min1=temp1->data;
            temp1=temp1->next;
        }
       head3 = Insert(head3, min1, i);
        i++;
       head1 = Delete(head1,min1);
    }

    while(head2!=NULL)
    {
      Node* temp2 = head2;
      int min2=head2->data;
      while(temp2!=NULL)
        {
            if(temp2->data<min2)
                min2=temp2->data;
            temp2=temp2->next;
        }
       head3 = Insert(head3, min2, i);
        i++;
       head2 = Delete(head2,min2);
    }
    return head3;

}
