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
    
    struct mycomp{
        bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
         }
    };
    
public:
  
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,mycomp> pq;
        for(auto curr:lists){
            if(curr) pq.push(curr);
        }
        if(pq.empty()) return NULL;
        
        ListNode* ans=pq.top();
        pq.pop();
        if(ans->next) pq.push(ans->next);
        
        ListNode* curr=ans;
        while(!pq.empty()){
            curr->next=pq.top();
            pq.pop();
            
            curr=curr->next;
            if(curr->next) pq.push(curr->next);
        }
        return ans;
    }
};