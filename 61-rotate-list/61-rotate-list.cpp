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
    int count(ListNode*head){
        int ans=0;
        while(head!=NULL){
            head=head->next;
            ans++;
        }
        
        return ans;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(k==0 || head==NULL || head->next==NULL){
            return head;
        }
        
         ListNode*tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        
        ListNode*fwd=head;
        ListNode*prev=NULL;
       
        
         int n=count(head);
        if(k%n==0){
            return head;
        }
        int in=n-k%n;
        
        
        for(int i=0;i<in;i++){
            prev=fwd;
            fwd=fwd->next;
        }
        
        prev->next=NULL;
        tail->next=head;
        
        return fwd;
        
        
        
       
    }
};