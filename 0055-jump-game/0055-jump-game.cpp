class Solution {
public:
int  solve (int i, vector<int> &nums, vector<int> &dp)
{
    if(i>=nums.size()-1)
    {
        return 1;                 // recursive solution 
    }

    // for(int jump=1;jump<=nums[i];jump++)
    // {   
    //     if(solve(i+jump, nums))
    //     return true;
    // }
    // return false;

    if(dp[i]!=-1)
    {
        return dp[i];
    }
    for(int jump=1;jump<=nums[i];jump++)
    {
        if(solve(i+jump,nums,dp))
        {
            dp[i]=1;
            return dp[i];
        }
    }

    return dp[i]=0;
}
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);

        return solve (0,nums,dp);
    }
};