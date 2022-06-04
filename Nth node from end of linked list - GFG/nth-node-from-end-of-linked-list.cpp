// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int count(Node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    
    return count;
}
int getNthFromLast(Node *head, int n)
{
       // Your code here
       if(head==NULL){
           return 0;
       }
       
       
       int k=count(head);
       
       if(n>k){
           return -1;
       }
       
       k=k-n;
       
       
       
       int i=0;
       Node*temp=head;
       while(i<k){
           temp=temp->next;
           i++;
       }
       
       return temp->data;
       
       
       
}
