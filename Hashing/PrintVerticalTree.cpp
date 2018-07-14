#include<iostream>
#include<list>
using namespace std;

list<int> *adj = new list<int>[6];

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

void inorder(Node* root,int HD)
{
    if(root==NULL)
        return;
    adj[HD+2].push_back(root->data);
    inorder(root->left,HD-1);
    inorder(root->right,HD+1);

}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right = newNode(3);
    root->right->right = newNode(7);
    root->right->left = newNode(6);
    root->right->right->right = newNode(9);
    root->right->left->right = newNode(8);
    inorder(root,0);

    cout<<"\n";
    list<int>::iterator i;
    for(int j=0;j<6;j++)
    {
      cout<<j<<"-";
      for(i=adj[j].begin();i!=adj[j].end();i++)
      {
          cout<<*i;
      }
      cout<<"\n";
    }

}
