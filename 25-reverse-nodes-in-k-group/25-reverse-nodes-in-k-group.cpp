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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int n=count(head);
        
        if(n<k){
            return head;
        }
        
        
        ListNode* curr=head;
        ListNode*prev=NULL;
        ListNode*fwd=NULL;
        
        int i=1;
        while(i<=k && curr!=NULL){
            i++;
            fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        
        ListNode* x=reverseKGroup(curr,k);
        head->next=x;
        return prev;        
    }
};