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
    
    ListNode* midFind(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode*slow=head;
        ListNode*fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
           slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
        
    }
    
    ListNode* reverse(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode*x=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        
        return x;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return true;
        }
        
        ListNode*mid=midFind(head);
        ListNode* head2=mid->next;
        mid->next=NULL;
        
        head2=reverse(head2);
        
        while(head2!=NULL){
            if(head->val!=head2->val){
                return false;
            }
            head=head->next;
            head2=head2->next;
        }
        
        return true;
        
    }
};