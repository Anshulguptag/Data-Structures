#include<bits/stdc++.h>
using namespace std;

const int Alphabet = 26;

struct Node
{
    Node *child[Alphabet];
    bool isChildNode;
};

Node* getNode()
{
    Node* pNode = new Node;
    pNode->isChildNode = false;
    for(int i=0;i<Alphabet;i++)
        pNode->child[i] = NULL;

    return pNode;
}

Node* Insert(Node* root,string key)
{
    Node* pCrawl = root;
    for(int i=0;i<key.length();i++)
    {
        if(isupper(key[i]))
            key[i] = tolower(key[i]);
        int index = key[i]-'a';
        if(!pCrawl->child[index])
            pCrawl->child[index] = getNode();

        pCrawl = pCrawl->child[index];
    }
    pCrawl->isChildNode = true;
    return root;
}

bool Search(Node* root,string key)
{
    Node* temp = root;
    for(int i=0;i<key.length();i++)
    {
        if(isupper(key[i]))
            key[i] = tolower(key[i]);
        int index = key[i]-'a';
        if(temp->child[index]==NULL)
            return false;
        temp = temp->child[index];
    }
    return (temp!=NULL && temp->isChildNode);
}
int main()
{
    string keys[] = {"the","child","TRIE","Try"};
    int size = *(&keys+1)-keys;
    Node* root = getNode();
    for(int i=0;i<size;i++)
    {
        root = Insert(root,keys[i]);
    }

    Search(root,"Try")?cout<<"true":cout<<"false";

}
