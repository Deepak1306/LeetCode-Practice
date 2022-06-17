// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
void swap(node*head , node*tail){
    int temp=head->data;
    head->data=tail->data;
    tail->data=temp;
}


node*partition(node*head,node*tail){
    int pivot=head->data;
    node*fwd=head->next;
    node*prev=head;
    
    while(fwd!=tail){
        if(fwd->data<pivot){
            prev=prev->next;
            swap(prev,fwd);
        }
        fwd=fwd->next;
    }
    
    swap(head,prev);
    
    return prev;
    
    
}


void sort(node*head,node*tail){
    if(head==NULL || head->next==NULL || head==tail){
        return ;
    }
    node*x=partition(head,tail);
    sort(head,x);
    sort(x->next,tail);
    
}


void quickSort(struct node **headRef) {
    node*head=*headRef;

  sort(head,NULL);
    
    
    
}