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
bool valid(TreeNode* root,int x)
{
    if(root==nullptr)
    {
        return true;
    }
    if(root->val!=x)
    {
        return false;
    }
    
    bool l=valid(root->left,x);
    bool r=valid(root->right,x);

    if(l && r)
    {
        return true;
    }
    {
        return false;
    }

}
    bool isUnivalTree(TreeNode* root) {
        bool check=valid(root,root->val);
        return check;
    }
};