#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

struct Nodetree
{
    int data;
    Nodetree* left;
    Nodetree* right;
};

Nodetree* newNode(int x)
{
    Nodetree* node = new Nodetree;
    node->data = x;
    node->left = node->right = NULL;

    return node;
}

Node* Insert(Node* head, int x)
{
    Node* node = new Node;
    node->data = x;
    if(head==NULL)
    {
        node->next = node->prev = NULL;
        head = node;
        return head;
    }
    Node* temp = head;
    while(temp->next!=NULL)
    {
        if(temp->data>x)
            break;
        temp = temp->next;
    }
    if(temp->data>x)
    {
        node->next = temp;
        node->prev = temp->prev;
        if(temp==head)
        {
           head = node;
        }
        else
        {
           temp->prev = node;

        }
        return head;
    }

    node->next = temp->next;
    node->prev = temp;
    temp->next = node;


    return head;
}
int getsize(Node* head)
{
    int count  = 0;
    while(head!=NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

Nodetree* InsertTree(Nodetree* root,int x)
{
    if(root==NULL) return newNode(x);
    if(root->data>x)
        root->left = InsertTree(root->left,x);
    else if(root->data<x)
        root->right = InsertTree(root->right,x);

    return root;
}

void preorder(Nodetree* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void DLLtoBST(Node* head)
{
    int i=0;
    Node* temp = head;
    while(i<(getsize(head)/2))
    {
        temp = temp->next;
        i++;
    }
    Nodetree* root = NULL;
    root = InsertTree(root,temp->data);
    while(head!=NULL)
    {
        if(head->data!=root->data)
            root = InsertTree(root,head->data);
        head = head->next;
    }
    preorder(root);
}

void Print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data;
        head = head->next;
    }
    cout<<"\n";
}

int main()
{
    Node* head = NULL;
    int arr[] = {1,2,3,4,5,6,7};
    int size = *(&arr+1)-arr;

    for(int i=0;i<size;i++)
        head = Insert(head, arr[i]);
    Print(head);
    DLLtoBST(head);
}
