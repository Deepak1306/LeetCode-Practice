// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_map<int,int>m;
    
    while(head1!=NULL){
        m[head1->data]=1;
        head1=head1->next;
    }
    
    Node*head=NULL;
    Node*tail=NULL;
    
    while(head2!=NULL){
        if(m.find(head2->data)!=m.end()){
            Node*newNode=new Node(head2->data);
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }else{
                
                tail->next=newNode;
                tail=newNode;
            }
            
            m.erase(head2->data);
            
        }
        head2=head2->next;
    }
    
    return head;
    
}