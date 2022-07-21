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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ans=new ListNode(0);
          ans->next=head;
        
        ListNode* curr=ans,*before,*after;
        while(left>=0 || right>=0){
            if(left==1) before=curr;
            if(right==0) after =curr->next;
            
            left--;right--;
            curr=curr->next;
            
        }
        
        curr=before->next;
        ListNode* prev=after;
        while(curr!=after){
            ListNode*nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        
        before->next=prev;
        
        return ans->next;
        
    }
};