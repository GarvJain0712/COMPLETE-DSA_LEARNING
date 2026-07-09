class Solution {
public:

    void output(TreeNode* root, vector<vector<int>>& ans)
    {
        if(root == nullptr)
        {
            return;
        }

        queue<pair<TreeNode*, int>> q;

        // {node, level}
        q.push({root, 0});

        while(!q.empty())
        {
            TreeNode* curr = q.front().first;
            int level = q.front().second;

            q.pop();

            // First node encountered at a new level
            if(level == ans.size())
            {
                ans.push_back({});
            }

            ans[level].push_back(curr->val);

            if(curr->left != nullptr)
            {
                q.push({curr->left, level + 1});
            }

            if(curr->right != nullptr)
            {
                q.push({curr->right, level + 1});
            }
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        output(root, ans);
        return ans;
    }
};