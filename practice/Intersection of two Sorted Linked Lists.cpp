#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* Insert(Node* head,int x)
{
    Node* node = new Node;
    node->data = x;
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

void Intersection(Node* head,Node* head1,Node* &head2)
{
    if(head==NULL || head1==NULL)
        return ;
    if(head->data<head1->data)
        return Intersection(head->next,head1,head2);
    if(head->data>head1->data)
        return Intersection(head,head1->next,head2);
    head2 = Insert(head2,head->data);
    Intersection(head->next,head1->next,head2);

}

void Traverse(Node* head)
{
   while(head!=NULL)
   {
       cout<<head->data<<"-->";
       head = head->next;
   }
   cout<<"NULL\n";
}
int main()
{
    int arr[] = {1,2,3,4,6};
    int arr1[] = {2,4,6,8};
    int n1 = *(&arr+1)-arr;
    int n2 = *(&arr1+1)-arr1;
    Node* head = NULL;
    Node* head1 = NULL;
    Node* head2 = NULL;
    for(int i=0;i<n1;i++)
        head = Insert(head,arr[i]);
    cout<<"List 1: ";
    Traverse(head);
    for(int j=0;j<n2;j++)
        head1 = Insert(head1,arr1[j]);
    cout<<"List 2: ";
    Traverse(head1);
    Intersection(head,head1,head2);
    cout<<"Intersecting List: ";
    Traverse(head2);
}
