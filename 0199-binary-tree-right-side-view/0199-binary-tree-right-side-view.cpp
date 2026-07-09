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
void view(TreeNode* root , vector<int > &ans )
{   
    if(root==nullptr)
    {
        return ;
    }
    queue<pair<TreeNode*,int>> q;
   

    q.push({root,0});

    while(!q.empty())
    {
        TreeNode* curr=q.front().first;
        int level=q.front().second;

        q.pop();

        if(level==ans.size())
        {
         ans.push_back(curr->val);
        }
  if(curr->right!=nullptr)
        {
            q.push({curr->right,level+1});
        }
        if(curr->left!=nullptr)
        {
            q.push({curr->left,level+1});
        }
      
    }

}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        view(root,ans);
        return ans;
    }
};