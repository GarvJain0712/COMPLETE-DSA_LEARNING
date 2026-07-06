class Solution {
public:
vector<vector<int>> ans;
vector<int> curr;
    void sum(vector<int>& candidates, int target,int idx)
    {
        if(target==0)
        {
            ans.push_back(curr);
            return ;
        }

        if(idx == candidates.size() || target < 0)
            return;

        curr.push_back(candidates[idx]);
        sum(candidates,target-candidates[idx],idx);
        curr.pop_back();

        sum(candidates,target,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum(candidates,target,0);
        return ans;
    }
};