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
    
    ListNode* removeNthFromEnd(ListNode* head, int k) {
       if(head==NULL){
           return head;
       }
        
        int n=count(head);
        if(k>n){
            return head;
        }
        if(n==1){
            return NULL;
        }
        
        k=n-k;
        
        if(k==0){
            return head->next;
        }
        
        ListNode*temp=head;
        ListNode* prev=NULL;
        ListNode* fwd=NULL;
        
        while(k && temp!=NULL){
            prev=temp;
            temp=temp->next;
            k--;
        }
        
        if(temp==NULL){
            return head;
        }
        
        fwd=temp->next;
        
        prev->next=fwd;
        
        return head;
        
    }
};