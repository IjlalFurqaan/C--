#include<iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    public:
    Node(int data1,Node* next1,Node* back1)
    {
        data=data1;
        next=next1;
        back=back1;
    }

    public:
    Node(int data1)
    {
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
Node* convertArraytoDll(vector<int> &arr)
{
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(size_t i=1;i<arr.size();i++)
    {
      Node* temp=new Node(arr[i],nullptr,prev);
      prev->next=temp;
      prev=temp;
    }
    return head;
}
 void print(Node* head)
 {
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
 }

Node* deleteHead(Node* head)
{
    if(head== NULL || head->next==NULL)
    {
        return NULL;
    }
    Node* prev=head;
    head = head->next;

    head->back=nullptr;
    prev->next=nullptr;

    delete prev;
    return head;
}

int main(){
    vector<int> arr= {1,0,1,2,3,4,5};
    Node* head =convertArraytoDll(arr);

    head=deleteHead(head);
    print(head);

}
