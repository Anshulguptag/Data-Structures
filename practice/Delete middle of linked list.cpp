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
    node->next = head;
    head = node;

    return head;
}

Node* Delete(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL && fast!=NULL)
    {
        fast = fast->next->next;
        if(fast==NULL || fast->next==NULL)
        {
            Node* temp = slow->next;
            slow->next = slow->next->next;
            delete temp;
            break;
        }
        slow = slow->next;
    }
    return head;
}
void Print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data;
        if(head->next!=NULL)
            cout<<"-->";
        head = head->next;
    }
    cout<<"\n";
}
int main()
{
    Node* head = NULL;
    head = Insert(head,4);
    head = Insert(head, 3);
    head = Insert(head, 2);
    head = Insert(head, 1);

    Print(head);
    head = Delete(head);
    Print(head);

}
