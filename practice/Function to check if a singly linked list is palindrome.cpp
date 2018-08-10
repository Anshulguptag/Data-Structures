#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

Node* Insert(Node* head,char x)
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
int getsize(Node* head)
{
    int count1 = 0;
    while(head!=NULL)
    {
        count1++;
        head = head->next;
    }
    return count1;
}

bool Palindrome(Node* head)
{
    Node* temp = head;
    int i=1;
    int n = ((getsize(head)+1)/2);
    if(getsize(head)%2==0)
        n = n+1;
    while(i<n)
    {
        Node* temp2 = temp->next;
        int j = i+1;
        while(j<(getsize(head)+1)-i)
        {
            j++;
            temp2 = temp2->next;
        }
        if(temp2->data!=temp->data)
            return false;
        temp = temp->next;
        i++;
    }
    return true;
}
int main()
{
    Node* head = NULL;
    string str = "abccba";
    for(int i=0;i<str.length();i++)
        head = Insert(head,str[i]);
    if(Palindrome(head))
        cout<<"Palimdrome";
    else
        cout<<"Not Palimdrome";
}
