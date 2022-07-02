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
            c++;
            head=head->next;
        }
        
        return c;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        
        int n=count(head);
        if(k>n || k==0){
            return head;
        }
        
        if(k==n){
            return head->next;
        }
        
        k=n-k;
        
        ListNode* temp=head;
        ListNode*prev=NULL;
        int i=1;
        while(i<=k){
            i++;
            prev=temp;
            temp=temp->next;
        }
        
        prev->next=temp->next;
        
        return head;
        
        
        
        
    }
};