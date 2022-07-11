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

class Solution
{
public:
    int solve(TreeNode *root, int &res)
    {
        if (root == NULL)
            return 0;

        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int temp = max(max(l, r) + root->val, root->val);
        int ans = max(temp, l + r + root->val);
        res = max(res, ans);
        return temp;
    }

    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};

// class Solution {
// public:
//     int ans=0;
//     void maxsum(TreeNode* root ,int &temp){
//         if(root->left==NULL && root->right==NULL){
//             ans=max(ans,temp);
//             return;
//         }
        
//         temp+=root->val;
        
//         maxsum(root->left,temp);
//         maxsum(root->right,temp);
//     }
//     int maxPathSum(TreeNode* root) {
        
//         if(root==NULL) return 0;
//         int temp=0;
//         maxsum(root,temp);
        
//         maxPathSum(root->left);
//         maxPathSum(root->right);
        
        
//         return ans;
//     }
// };