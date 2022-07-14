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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int &index,int l,int h,        unordered_map<int,int> &mp) {
        if(l>h) return NULL;
        
        int pivot=mp[preorder[index]];
        
        TreeNode *head=new TreeNode (inorder[pivot]);
        index++;
        
        head->left=build(preorder,inorder,index,l,pivot-1,mp);
        head->right=build(preorder,inorder,index,pivot+1,h,mp);
        
        return head;
              
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,inorder,index,0,inorder.size()-1,mp);
    }
};