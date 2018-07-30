#include<bits/stdc++.h>
using namespace std;

list<int> *adj = new list<int>[5];

struct Node
{
    int data;
    Node* left;
    Node* right;
};

void Print(Node* root)
{
    if(root==NULL)
        return;
    if(root->left!=NULL)
        adj[root->data].push_back(root->left->data);
    if(root->right!=NULL)
        adj[root->data].push_back(root->right->data);
    Print(root->left);
    Print(root->right);
}

Node* newNode(int x)
{
    Node* node = new Node;
    node->data = x;
    node->left = node->right = NULL;
    return node;
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    Print(root);

    list<int>::iterator i1;
    bool visited[] = {false,false,false,false,false};
    for(int i=1;i<5;i++)
    {
        if(!visited[i-1])
        {
          cout<<i;
          visited[i-1] = true;
        }

        for(i1=adj[i].begin();i1!=adj[i].end();i1++)
            if(!visited[*i1-1])
            {
              cout<<*i1;
              visited[*i1-1] = true;
            }

    }

}
