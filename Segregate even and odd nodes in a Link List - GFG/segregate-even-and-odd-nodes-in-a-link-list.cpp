// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node*even=NULL;
        Node*tail1=NULL;
        Node*odd=NULL;
        Node*tail2=NULL;
        
        Node*temp=head;
        while(temp!=NULL){
            Node* newNode=new Node(temp->data);
            if(temp->data%2==0){
                if(even==NULL){
                    even=newNode;
                    tail1=newNode;
                }else{
                    tail1->next=newNode;
                    tail1=newNode;
                }
                
                
            }else{
                
                if(odd==NULL){
                    odd=newNode;
                    tail2=newNode;
                }else{
                    tail2->next=newNode;
                    tail2=newNode;
                }
            }
            temp=temp->next;
        }
        if(even==NULL){
            return odd;
        }
        tail1->next=odd;
        return even;
        
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends