/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& nums,int i,int j){
        if(i>j) return NULL;
        
        int mid=(i+j)/2;
        TreeNode* head=new TreeNode(nums[mid]);
        
         head->left=build(nums,i,mid-1);
         head->right=build(nums,mid+1,j);
        
        return head;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return build(nums,0,nums.size()-1);
    }
};