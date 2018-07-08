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

void inorder(Node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* leftSubtree(Node* root,Node* ROOT)
{
   if(root==NULL) return NULL;
   if(root->data>ROOT->data)
      return root;
   leftSubtree(root->left,ROOT);
   leftSubtree(root->right,ROOT);
}

Node* rightSubtree(Node* root,Node* ROOT)
{
   if(root==NULL) return NULL;
   if(root->data<ROOT->data)
      return root;
   rightSubtree(root->left,ROOT);
   rightSubtree(root->right,ROOT);
}

Node* swapNodes(Node* root)
{
    if(root==NULL)
        return root;
     Node* temp = leftSubtree(root->left,root);
     Node* temp1 = rightSubtree(root->right,root);
     int temp2 = temp->data;
     temp->data = temp1->data;
     temp1->data = temp2;

    return root;
}

int main()
{
    Node* root = newNode(6);
    root->left        = newNode(10);
    root->right       = newNode(2);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);
    cout<<"Inorder Traversal of the original tree\n";
    inorder(root);
    root = swapNodes(root);
    cout<<"\nInorder Traversal of the fixed tree\n";
    inorder(root);

}
