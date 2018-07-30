#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* Insert(Node* head,int data)
{
    Node* node = new Node;
    node->data = data;
    if(head==NULL)
    {
        node->next = head;
        head = node;
        return head;
    }
    Node* temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    node->next = temp->next;
    temp->next = node;

    return head;
}

int List2Num(Node* head)
{
    int sum = 0 ;
    Node* temp =head;
    int i=0;
    while(temp!=NULL)
    {
        sum = sum+(temp->data)*(pow(10,i));
        i++;
        temp = temp->next;
    }
    return sum;
}

void Print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;
    Node* head1 = NULL;
    Node* result = NULL;

    head = Insert(head,5);
    head = Insert(head,6);
    head = Insert(head,3);
    cout<<"First List is ";
    Print(head);
    int n1 = List2Num(head);

    head1 = Insert(head1,8);
    head1 = Insert(head1,4);
    head1 = Insert(head1,2);
    cout<<"\nSecond List is ";
    Print(head1);

    int n2 = List2Num(head1);

    int result1 = n1 + n2;

    while(result1!=0)
    {
        int rem = result1%10;
        result = Insert(result,rem);
        result1 = result1/10;
    }
    cout<<"\nResultant List is ";
    Print(result);

}
