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
    bool evaluatesum(TreeNode* root , int targetSum , int sum)
    {
        if(root==nullptr)
        {
            return false;
        }

        sum=sum+root->val;
        if(root->left==nullptr && root ->right==nullptr)
        {
            if(sum==targetSum)
            {
                return true;
            }
        }
        return (evaluatesum(root->left,targetSum,sum) || evaluatesum(root->right,targetSum,sum));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans=evaluatesum(root,targetSum,0);
        return ans;
    }
};