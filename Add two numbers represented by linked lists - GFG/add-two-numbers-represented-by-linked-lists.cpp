// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node*curr =head;
        Node*prev=NULL;
        Node*fwd=NULL;
        
        while(curr!=NULL){
            fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        
        return prev;
        
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        if(first==NULL){
            return second;
        }else if(second==NULL){
            return first;
        }
        
        Node* head1=reverse(first);
        Node* head2=reverse(second);
        
        Node* temp1=head1;
        Node* temp2=head2;
        
        
        Node*head=NULL;
        Node*tail=NULL;
        
        
        int carry=0;
        while(temp1!=NULL || temp2!=NULL){
            int a=temp1?temp1->data:0;
            int b=temp2?temp2->data:0;
            
            int sum=a+b+carry;
            carry=sum/10;
            sum=sum%10;
            
            Node*newNode=new Node(sum);
            
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }else{
                tail->next=newNode;
                tail=newNode;
            }
            
            temp1=temp1?temp1->next:NULL;
            temp2=temp2?temp2->next:NULL;
        }
        
        if(carry!=0){
                Node*newNode=new Node(carry);
            
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }else{
                tail->next=newNode;
                tail=newNode;
            }
        }
        
        
        head=reverse(head);
        return head;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends