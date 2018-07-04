#include<iostream>
#include<string.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* Push(Node* head,int x)
{
    Node* node = new Node;
    node->data = x;
    if(head == NULL)
    {
        node->next = head;
        node->prev = head;
        head = node;
        return head;
    }
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node->next = temp->next;
    node->prev = temp;
    temp->next = node;

    return head;
}

void Print(Node* head)
{
    while(head!=NULL)
    {
        cout<<char(head->data);
        head = head->next;
    }
}

Node* Balfunction(Node* head, Node* temp,Node* temp2,char symbol)
{
       if(temp==head)
        {
            head = temp2->next;
            return head;
        }

        if(char(temp->data)==symbol)
        {
            temp->prev->next = temp2->next;
            temp2->next->prev = temp->prev;
            return head;
        }

        else{
            cout<<"\nUnbalanced";
            return 0;
        }
}
Node* checkBalanced(Node* head)
{
    Node* temp = head;
    Node* temp2 = temp->next;

    if(char(temp->data)==')' || char(temp->data)=='}' || char(temp->data)==']' || temp2==NULL)
    {
      cout<<"\nUnbalanced";
      return 0;
    }

    while(temp2->next!=NULL)
    {
        if(char(temp2->data)=='}')
        {
            return Balfunction(head, temp, temp2, '{');
        }
        if(char(temp2->data)==']')
        {
            return Balfunction(head, temp, temp2, '[');
        }
        if(char(temp2->data)==')')
        {
            return Balfunction(head, temp, temp2, '(');
        }
        temp=temp->next;
        temp2=temp2->next;
    }
    return head;
}
int main()
{
    Node* head = NULL;
    char ch[] = "{}()[]{([{([]}])";
    for(int i = 0;i<strlen(ch);i++)
    {
        head = Push(head, int(ch[i]));
    }
    Print(head);
    int flag=0;
    for(int i=0;i<(strlen(ch)/2)+1;i++)
    {
            head = checkBalanced(head);
            if(head==0)
            {
                flag = 1;
                break;
            }

    }
    if(flag==0)
        cout<<"\nBalanced";
    return 0;
}
