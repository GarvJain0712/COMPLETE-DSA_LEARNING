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
    bool check(TreeNode* root , TreeNode* min , TreeNode* max)
    {
        if(root==nullptr)
        {
            return true;
        }
      if(min !=nullptr && root->val<=min->val)
      {
        return false;
      }
      if(max!=nullptr && root->val>=max->val)
      {
        return false;
      }
      return check(root->left,min,root) &&
      check(root->right,root,max);



       

      

    }
    bool isValidBST(TreeNode* root) {
        bool ans=check(root,nullptr,nullptr);
        return ans;
    }
};