/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int count(ListNode* head){
        int c=0;
        
        while(head!=NULL){
            c++;
            head=head->next;
        }
        return c;
        
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=count(headA);
        int m=count(headB);
        
        if(m>n){
            int i=1;
            while(i<=m-n){
                i++;
                headB=headB->next;
            }
            
        }
        else if(n>m){
             int i=1;
            while(i<=n-m){
                i++;
                headA=headA->next;
            }
        }
        
        
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        
        return headA;
        
    }
};