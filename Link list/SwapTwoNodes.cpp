#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

Node* Insert(Node* head, int x, int pos);
void Print(Node* head);
Node* SwapNodes(Node* head, int x, int y);
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
    int swap1,swap2;
    cout<<"Enter the elements to be swap but not be adjacent: ";
    cin>>swap1>>swap2;
    head = SwapNodes(head,swap1,swap2);
    Print(head);
    return 0;
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


//SwapNodes Function
Node* SwapNodes(Node* head, int x, int y)
{
    Node* temp; //It is for swapping
    Node* temp1 = head;
    Node* temp2 = head;
    Node* a = NULL;
    Node* b = NULL;
    int flag1=0, flag2=0;
    if(x==y)
    {
        cout<<"Both the values are same so their is no swapping :(\n";
        return head;
    }
    if(head->data==x)
    {
        a = head;
        flag1 = 1;
    }
    else
    {
       while(temp1!=NULL)
        {
            if(temp1->next->data==x)
            {
                a = temp1->next;
                break;
            }
            temp1 = temp1->next;
        }
    }
    if(head->data==y)
    {
        b = head;
        flag2 = 1;
    }
    else{
       while(temp2->next!=NULL)
        {
            if(temp2->next->data==y)
            {
                b = temp2->next;
                break;
            }
            temp2 = temp2->next;
        }
    }
    temp = a;
    a = b;
    b = temp;

    temp = a->next;
    a->next = b->next;
    b->next = temp;

    if(flag1==1)
    {
        head = a;
    }
    else{
      temp1->next = a;
    }

    if(flag2==1)
    {
        head = b;
    }
    else{
      temp2->next = b;
    }
    return head;
}
