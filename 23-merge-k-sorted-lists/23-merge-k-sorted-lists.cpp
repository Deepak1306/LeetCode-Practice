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
    ListNode* merge(ListNode* head1,ListNode* head2){
        if(head2==NULL){
            return head1;
        }
        else if(head1==NULL){
            return head2;
        }
        
        ListNode*head=NULL;
        ListNode*tail=NULL;
        
        if(head1->val<=head2->val){
            head=head1;
            tail=head1;
            head1=head1->next;
        }else{
            head=head2;
            tail=head2;
            head2=head2->next;
        }
        
        while(head1!=NULL && head2!=NULL){
            
           if(head1->val<=head2->val){
               tail->next=head1;
               tail=head1;
               head1=head1->next;
              
           }else{
               tail->next=head2;
               tail=head2;
               head2=head2->next;
             
           }
        
        }
        if(head1!=NULL){
            tail->next=head1;
        }
        if(head2!=NULL){
            tail->next=head2;
        }
        
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         int n=lists.size();
        if(n==0){
            return NULL;
        }
              
        ListNode* ans=lists[0];
        
        for(int i=1;i<n;i++){
          ans = merge(ans,lists[i]);
        }
        
        return ans;
    }
};