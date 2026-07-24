class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int >mp;

        mp[0]=-1;    // remainder 0
        int prefixsum=0;
        for(int i=0;i<nums.size();i++)
        {
            prefixsum+=nums[i];

            int rem=prefixsum%k;

            if(mp.count(rem))
            {
                if(i-mp[rem]>=2)
                {
                    return true ;
                }
            }
            else
            {
                mp[rem]=i;
            }
        }
        return false;
    }
};