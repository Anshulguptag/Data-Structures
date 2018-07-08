#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x)
{
    Node* node = new Node;
    node->data = x;
    node->left = node->right = NULL;

    return node;
}

Node* Insert(Node* root, int x)
{
    if(root==NULL) return newNode(x);
    if(root->data>x)
        root->left = Insert(root->left,x);
    else if(root->data<x)
        root->right = Insert(root->right,x);

    return root;
}

void inorder(Node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
stack<int> s;
stack<int> s1;
void AuxStack(Node* root, int flag)
{
    if(root==NULL) return;
    AuxStack(root->left,flag);
    if(flag==0)
        s.push(root->data);
    else
        s1.push(root->data);
    AuxStack(root->right,flag);
}
void FindNodes(Node* root, int target)
{
    AuxStack(root,0);
    int flag = 0;
    while(!s.empty())
    {
        AuxStack(root,1);
        while(!s1.empty())
        {
            if(s1.top()+s.top()==target)
            {
                flag = 1;
                break;
            }
            s1.pop();
        }
        if(flag==1)
        {
            cout<<"Pair Found: "<<s1.top()<<" + "<<s.top()<<" = "<<target;
            break;
        }
        s.pop();
    }
}

int main()
{
    int arr[] = {15,8,12,16,25,20,10};
    int size = *(&arr+1)-arr;
    Node* root = NULL;
    for(int i=0;i<size;i++)
        root = Insert(root,arr[i]);

    //inorder(root);
    FindNodes(root,41);

}
