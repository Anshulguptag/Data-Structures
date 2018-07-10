#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;

    return node;
}

Node* Insert(Node* root, int data)
{
    if(root==NULL) return newNode(data);
    if(root->data>data)
        root->left = Insert(root->left,data);
    else if(root->right,data)
        root->right = Insert(root->right,data);

    return root;
}

void inorder(Node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int arr[])
{
    for(int i=0;i<4;i++)
    {
        for(int j=i+1;j<5;j++)
        {
          if(arr[i]>arr[j])
            Swap(&arr[i],&arr[j]);
        }
    }
}
void storeInorder(Node* root,int arr[],int *i)
{
    if(root == NULL) return ;
    storeInorder(root->left,arr,i);
    arr[*i] = root->data;
    (*i)++;
    storeInorder(root->right,arr,i);
}
Node* BST(Node* root)
{
    int* arr = new int[5];
    int i=0;
    storeInorder(root,arr,&i);
    BubbleSort(arr);
    root = NULL;
    for(i=0;i<5;i++)
        root = Insert(root,arr[i]);
    return root;
}
int main()
{
    Node* root = NULL;
    root = newNode(10);
    root->left = newNode(2);
    root->left->left = newNode(8);
    root->left->right = newNode(4);
    root->right = newNode(7);
    cout<<"Binary Tree: \n";
    inorder(root);

    Node* root1 = NULL;
    root = BST(root);

    cout<<"\nBinary Search Tree: \n";
    inorder(root);
}
