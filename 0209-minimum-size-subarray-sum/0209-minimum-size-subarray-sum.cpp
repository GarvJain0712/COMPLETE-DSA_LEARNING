class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        
        int sum =0;
        int minl=INT_MAX;
        for(int right=0;right<nums.size();right++)
        {
            sum+=nums[right];
            while(sum>=target)
            {
                int length=right-left+1;
                minl=min(length,minl);
                sum-=nums[left];
                left++;
            }
        }
        if(minl==INT_MAX)
        {
            return 0;
        }
        else
        {
             return minl;
        }
       
    }
};