#include<iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1,Node* next1)
    {
        data=data1;
        next=next1;
    }

    public:
    Node(int data1)
    {
        data=data1;
        next=nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head =new Node(arr[0]);
    Node* mover=head;
    for(size_t i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;

}

int lengthOfLL(Node* head)
{
    int cnt=0;
    Node* temp =head;
    while(temp)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

int searchinLL(Node* head, int val)
{
    Node* temp =head;
    while(temp)
    {
        if(temp->data==val)
        return 1;
        temp=temp->next;
    }
    return 0;
}
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";  // Print the data of each node
        temp = temp->next;  // Move to the next node
    }
    cout << endl;
}
Node* removesTail(Node* head)
{
    Node* temp =head;
    if(head==NULL || temp->next==NULL)
    {
        return NULL;
    }
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;

}
Node* insertPosition(Node*head ,int el , int k)
{
    if(head==NULL)
    {
        if(k==1)
        {
            return new Node(el);
        }
    }
    if(k==1)
    {
        return new Node(el,head);
    }
    int cnt=0;
    Node* temp= head;
    while(temp!=NULL)
     {
        cnt++;
    if(cnt==k-1)
    {
        Node* x=new Node(el, temp->next);
        temp->next=x;
        break;

    }
    temp=temp->next;
     }
    return head;
 } 

int main()
{
    // int val;
    vector<int> arr={1,2,3,4};
    // Node* temp =head;
    Node* head=convertArr2LL(arr);
    // while(temp)
    // {
    //     cout<<temp->data<<" ";
    //     temp=temp->next;

    // }

    // cout<<endl<<"Length is "<<lengthOfLL(head);
    // cin>>val;

    // cout<<endl<<" Element is"<<searchinLL(head,val);
    //  head=removesTail(head);
    head=insertPosition(head,100,3);

     print(head);

}