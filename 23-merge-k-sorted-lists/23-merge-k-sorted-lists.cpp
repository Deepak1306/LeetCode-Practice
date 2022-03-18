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
    ListNode*mergeList(ListNode*list1,ListNode*list2){
        if(list1==NULL){
            return list2;
        }else if(list2==NULL){
            return list1;
        }
        
        ListNode*head=NULL;
        ListNode*tail=NULL;
        
        if(list1->val < list2->val){
            head=list1;
            tail=list1;
            list1=list1->next;
        }else{
            head=list2;
            tail=list2;
            list2=list2->next;
        }
        
        while(list1!=NULL && list2!=NULL){
             if(list1->val < list2->val){
                tail->next=list1;
                tail=list1;
                list1=list1->next;
            }else{
                tail->next=list2;
                tail=list2;
                list2=list2->next;
            }
       
        }
        if(list1!=NULL){
            tail->next=list1;
            return head;
        }else{
            tail->next=list2;
            return head;
        }
        
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        
        if(n==0){
            return NULL;
        }
        
        
        ListNode*head=lists[0];
        ListNode*temp=NULL;
        
        for(int i=1;i<n;i++){
            temp=lists[i];
            head=mergeList(head,temp);
            
        }
        
        return head;
    }
};