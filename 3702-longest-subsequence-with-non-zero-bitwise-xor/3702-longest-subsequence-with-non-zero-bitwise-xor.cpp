class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0;
        int n=nums.size();
        bool nonzero=false;
        for(int num: nums)
        {
            x=x^num;
            if(num!=0)
            {
                nonzero=true;
            }
        }
        if(x!=0)
        {
            return n;
        }
        else
        {
            if(nonzero)
            {
                return n-1;
            }
            else
            {
                return 0;
            }
        }
    }
};