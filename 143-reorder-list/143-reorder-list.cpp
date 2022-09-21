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
    
    ListNode* midNode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* fwd=NULL;
        
        while(curr!=NULL){
            fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return ;
        }
        
        ListNode*mid=midNode(head);
        ListNode* head2=mid->next;
        mid->next=NULL;
        
        head2=reverse(head2);
        
        ListNode* temp=head;
        while(head2!=NULL){
            ListNode*x=head2;
            head2=head2->next;
            
            x->next=temp->next;
            temp->next=x;
            
            temp=x->next;
        }
    }
};