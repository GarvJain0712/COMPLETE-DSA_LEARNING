/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool roottonode(TreeNode* root,TreeNode* n1,vector<TreeNode*> &path)
    {
        if(root==nullptr)
        {
            return false;
        }
 path.push_back(root);
        if(root==n1)
        {
            return true;
        }
       

       if(roottonode(root->left, n1, path) ||
   roottonode(root->right, n1, path))
{
    return true;
}

       

        path.pop_back();

        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        roottonode(root,p,path1);
        roottonode(root,q,path2);

        TreeNode* ans=nullptr;
int n = min(path1.size(), path2.size());

for(int i = 0; i < n; i++)
{
    if(path1[i] == path2[i])
    {
        ans = path1[i];
    }
    else
    {
        break;
    }
}

return ans;
    }
};