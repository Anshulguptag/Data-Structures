#include<iostream>
#include<string.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* Push(Node* head, int x)
{
    Node* node = new Node;
    node->data = x;
    node->next = head;
    head = node;

    return head;
}

void Print(Node* head)
{
    if(head == NULL)
    {
        cout<<"Top-->-1";
    }
    else
    {
        while(head!=NULL)
        {
            cout<<char(head->data);
            head = head->next;
        }
        cout<<"\n";
    }

}

int main()
{
    Node* head = NULL;
    char ch[] = "GeeksforGeeks";
    cout<<"String is: "<<ch;
    int *arr = new int[strlen(ch)];
    for(int i=0;i<strlen(ch);i++)
    {
        head = Push(head,int(ch[i]));
    }
    cout<<"\nReverse String is: ";
    Print(head);
    return 0;
}
