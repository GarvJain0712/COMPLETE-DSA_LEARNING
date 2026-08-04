class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int > ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();

        for(int i=0;i<n-1;i++)
        {
            int j=i+1;
            if (nums[i] == nums[j])
                    continue;

                for (int x = nums[i] + 1; x < nums[j]; x++)
                {
                    ans.push_back(x);
                }
        }
        return ans;
    }
};