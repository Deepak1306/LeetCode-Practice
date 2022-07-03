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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }else if(l2==NULL){
            return l1;
        }
        
        ListNode* head=new ListNode(0);
        ListNode* tail=head;
        
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            int a=l1==NULL?0: l1->val;
            int b=l2==NULL?0:l2->val;
            
            int sum=a+b+carry;
            carry=sum/10;
            sum=sum%10;
            
            ListNode* newNode=new ListNode(sum);
            tail->next=newNode;
            tail=newNode;
            
            l1=l1?l1->next:NULL;
            l2=l2?l2->next:NULL;
        }
        
        if(carry!=0){
            ListNode* newNode=new ListNode(carry);
            tail->next=newNode;
            tail=newNode;
        }
        
        return head->next;
        
    }
};