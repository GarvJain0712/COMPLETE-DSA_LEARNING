class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxsum=nums[0];
        int currsum=nums[0];

        for(int i=1; i<nums.size();i++)
        {   
            if(nums[i-1]<nums[i])
            {
                currsum+=nums[i];
            }
            else
            {
                currsum=nums[i];
            }
            maxsum=max(currsum,maxsum);
        }
        return maxsum;
    }
};