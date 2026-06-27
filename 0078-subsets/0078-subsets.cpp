class Solution {
public:
   vector<vector<int>> ans ;
    vector<int> curr;
    void solve (vector<int> arr , int i)
    {
        if(i==arr.size())
        {
            ans.push_back(curr);
            return ;
        }
        curr.push_back(arr[i]);
        solve(arr,i+1);

        curr.pop_back();

        solve(arr,i+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
};