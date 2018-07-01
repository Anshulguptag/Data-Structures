#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

Node* Insert(Node* head, int x);
void Print(Node* head);
int sum(Node* head);
int main()
{
    Node* head = NULL;
    cout<<"List 1: ";
    cout<<"How many Numbers: ";
    int n,i,x;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cout<<"Enter a number to be insert: ";
        cin>>x;
        head = Insert(head, x);

    }
    Node* head2 = NULL;
    cout<<"List 2: ";
    cout<<"How many Numbers: ";
    cin>>n;
    for (i=0;i<n;i++)
    {
        cout<<"Enter a number to be insert: ";
        cin>>x;
        head2 = Insert(head2, x);

    }
    Node* head3 = NULL;
    int sum1 = sum(head)+sum(head2);
    int digits = 0;
    int num = sum1;
    while(num!=0)
    {
        num /= 10;
        digits++;
    }
    int remainder;
    for(i=0;i<digits;i++)
    {

       remainder = sum1%10;
       sum1 = sum1/10;
       head3 = Insert(head3,remainder);

    }
    cout<<"First List: ";
    Print(head);
    cout<<"\nSecond List: ";
    Print(head2);
    cout<<"\nResultant List: ";
    Print(head3);
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

int sum(Node* head)
{
    Node* temp = head;
    int i = 0, sum=0;
    while(temp!=NULL)
    {
        sum = sum + temp->data*pow(10, i);
        ++i;
        temp = temp->next;
    }
    return sum;
}
