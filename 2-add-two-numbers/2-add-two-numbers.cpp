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
        
        ListNode*head=NULL;
        ListNode*tail=NULL;
        
        int carry=0;
        
        while(l1 ||l2){
          int v1=l1?l1->val:0;
          int v2=l2?l2->val:0;
          
          int value=v1+v2+carry;
          
            int v=value%10;
            carry=value/10;
            
            ListNode*newNode=new ListNode(v);
            
            if(!head){
                head=newNode;
                tail=newNode;
                
            }else{
                tail->next=newNode;
                tail=newNode;
            }
            
            l1=l1?l1->next:NULL;
            l2=l2?l2->next:NULL;
            
            
        }
        
        if(carry>0){
            ListNode*newNode=new ListNode(carry);
            tail->next=newNode;
            tail=tail->next;
        }
        
        return head;
        
    }
};