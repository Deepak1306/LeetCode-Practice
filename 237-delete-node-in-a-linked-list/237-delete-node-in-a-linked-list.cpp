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
    void deleteNode(ListNode* node) {
        ListNode* x=node;
        ListNode*prev=NULL;
        while(x->next!=NULL){
            x->val=x->next->val;
            prev=x;
            x=x->next;
        }
        
        prev->next=NULL;
    }
};