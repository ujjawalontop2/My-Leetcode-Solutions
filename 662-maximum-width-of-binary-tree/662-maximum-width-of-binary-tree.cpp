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
    int widthOfBinaryTree(TreeNode* root) {
         if(!root)
        {
            return 0;
        }
        queue<pair<TreeNode *,long long int>>q;
        q.push({root,0});
        long long int ans=0;
        while(!q.empty())
        {
           long long int n=q.size(),start=q.front().second;
            ans=max(ans,q.back().second-q.front().second+1);
            while(n)
            {
                auto node=q.front();
                q.pop();
               long long int index=node.second-start;
                if(node.first->left)
                {
                    q.push({node.first->left,2*index+1});
                }
                if(node.first->right)
                {
                    q.push({node.first->right,2*index+2});
                }
                n--;
            }
        }
        return ans;
    }
};