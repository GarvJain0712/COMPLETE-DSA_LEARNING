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
TreeNode* convert(TreeNode* root,int x)
{
    if(root==nullptr)
    {
        return new TreeNode(x);
    }

    if(x<root->val)
    {
        root->left=convert(root->left,x);
    }
    if(x>root->val)
    {
        root->right=convert(root->right,x);
    }

    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=nullptr;

        for(int i=0;i<preorder.size();i++)
        {
            root=convert(root,preorder[i]);
        }
        return root;
    }
};