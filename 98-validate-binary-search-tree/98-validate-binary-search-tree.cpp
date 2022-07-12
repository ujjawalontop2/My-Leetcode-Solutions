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
    
    bool check(TreeNode* root,TreeNode*l,TreeNode*r){
        
        if(root==NULL) return true;
        
        if(l && root->val <= l->val )
            return false;
        
        if(r && root->val >= r->val)
            return false;
        
        return check(root->left,l,root) && check(root->right,root,r);
    }
    
    bool isValidBST(TreeNode* root) {
        
        if(!root -> left && !root->right)
            return true;
        
        TreeNode*l=NULL,*r=NULL;
        
        return check(root,l,r);
    }
};