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
    int count(ListNode* l1){
        int ans=0;
        while(l1!=NULL){
            ans++;
            l1=l1->next;
        }
        
        return ans;
        
    }
    void add(ListNode* l1,ListNode* l2,int carry,ListNode*temp){
        if(l1==NULL && carry!=0){
            ListNode*newNode=new ListNode(carry);
            temp->next=newNode;
            return ;
        }else if(l1==NULL && carry==0){
            return;
        }
        else if(l1!=NULL && l2==NULL && carry==0){
            return ;
        }else if(l1!=NULL && l2==NULL && carry!=0){
            int a=l1->val+carry;
            l1->val=a%10;
            carry=a/10;
            add(l1->next,l2,carry,l1);
            return;
            
        }
        
        int sum=l1->val+l2->val+carry;
        l1->val=sum%10;
        carry=sum/10;
        
          add(l1->next,l2->next,carry,l1);
        
        return;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
       int count1=count(l1);
       int count2=count(l2);
        
        if(count1>count2){
            add(l1,l2,0,NULL);
            return l1;
        }else{
            add(l2,l1,0,NULL);
            return l2;
        }
        
        
    }
};