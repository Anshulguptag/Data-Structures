#include<iostream>
using namespace std;

struct Node
{
    int petrol;
    int distance;
    int pumpno;
    Node* next;
};

Node* Insert(Node* head, int petrol, int distance, int pumpno)
{
    Node* node = new Node;
    node->petrol = petrol;
    node->distance = distance;
    node->pumpno = pumpno;
    if(head == NULL)
    {
        head = node;
        node->next = node;
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    Node* temp = head;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            break;
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
    return head;
}

void Print(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(slow && fast && fast->next)
    {
        cout<<"{"<<slow->petrol<<", "<<slow->distance<<"}";
        cout<<"\n";
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            break;
    }
    cout<<"\n";
}
Node* startPetrolPump(Node* head)
{
    int sum = 0;
    int diff =0;
    Node* temp  = head;
    Node* temp2 = head;
    while(1)
    {
        sum = sum+temp2->petrol;
        int diff = sum - (temp2->distance);
        temp2=temp2->next;
        if(diff<0)
        {
            //startPetrolPump(head->next);
            return head->next;
        }
        sum = diff;
        if(temp == temp2)
        {
            break;
        }
    }
    cout<<"start = "<<temp->pumpno;
}
int main()
{
    Node* head = NULL;
    int petrol[] = {4,6,7,4};
    int dist[] = {6,5,3,5};
    for(int i=0;i<4;i++)
    {
        head = Insert(head,petrol[i],dist[i],(i+1));
    }
    //Print(head);
    int i=0;
    while(i<=4)
    {
       head = startPetrolPump(head);
       if(head==0)
          break;
       i++;
    }
    if(i==5)
        cout<<"No Solution";
}
