class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            int maxn=INT_MIN;
            int minn=INT_MAX;

            for(int j=0;j<=i;j++)
            {
                maxn=max(maxn,nums[j]);
            }
            for(int j=i;j<n;j++ )
            {
                minn=min(minn,nums[j]);
            }

            if(maxn-minn<=k)
            {
                return i;
            }
        }
        return -1;
    }
};