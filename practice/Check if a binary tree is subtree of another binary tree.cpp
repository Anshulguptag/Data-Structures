#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;
};

Node* newNode(char x)
{
    Node* node = new Node;
    node->data = x;
    node->left = node->right = NULL;

    return node;
}
void Traverse(vector<char> &v,Node* root)
{
    if(root==NULL)
    {
        v.push_back('\0');
        return;
    }

    v.push_back(root->data);
    Traverse(v,root->left);
    Traverse(v,root->right);
}

bool isSubTree(Node* root,Node* root1)
{
    vector<char> v;
    vector<char> v1;
    Traverse(v,root);
    Traverse(v1,root1);
    int j=0;
    for(int i=0;i<v1.size()-v.size()+1;i++)
    {
        int n = 0;
        int k =i;
        for(int j = 0;j<v.size();j++)
        {
            if(v[j]==v1[k])
                n++;
            k++;
        }
        if(n==min(v.size(),v1.size()))
            return true;
    }
    return false;
}
int main()
{
    Node* S = newNode('a');
    S->left = newNode('b');
    S->right = newNode('d');
    S->left->right = newNode('c');

    Node* T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');

    if (isSubTree(S, T))
        cout << "Yes: S is a subtree of T";
    else
        cout << "No: S is NOT a subtree of T";

}
