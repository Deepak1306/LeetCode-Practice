/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    int count(ListNode* head){
        int c=0;
        while(head!=NULL){
            head=head->next;
            c++;
        }
        
        return c;
    }
    
    
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        int l=count(head);
        if(k>l){
            return head;
        }
    
        int i=k;
        int j=l-k+1;
        
        if(i==j){
            return head;
        }
        
        if(j<i){
            swap(i,j);
        }
        
if(i==1 || j==1){
         
        if(abs(i-j)==1){
             ListNode*x=head->next;
             ListNode*y=head->next->next;
            x->next=head;
            head->next=y;
           
            return x;
        }
        else{
             ListNode*fwd=head;
             ListNode* prev=NULL;
            for(int k=1;k<j;k++){
                prev=fwd;
                fwd=fwd->next;
            }
             
            ListNode*x=fwd->next;
            fwd->next=head->next;
            prev->next=head;
            head->next=x;
            head=fwd;
             return head;
        }
        
       
    }
    else{
    
        if(abs(i-j)==1){
            ListNode*fwd=head;
            ListNode*prev=NULL;
            for(int k=1;k<i;k++){
                prev=fwd;
                fwd=fwd->next;
            }
            ListNode*x=fwd->next;
            ListNode*y=x->next;
            
            prev->next=x;
            x->next=fwd;
            fwd->next=y;
            return head;
            
        }
        else{
             ListNode*temp1=head;
             ListNode*temp2=NULL;
            for(int k=1;k<i;k++){
                temp2=temp1;
                temp1=temp1->next;
            }
            ListNode*x=temp1;
            ListNode*prev=NULL;
            for(int k=i;k<j;k++){
                prev=temp1;
                temp1=temp1->next;
            }
            ListNode*y=temp1->next;
            temp2->next=temp1;
            temp1->next=x->next;
            prev->next=x;
            x->next=y;
            return head;
            
            
        }
        
    }
        
        
    }
};