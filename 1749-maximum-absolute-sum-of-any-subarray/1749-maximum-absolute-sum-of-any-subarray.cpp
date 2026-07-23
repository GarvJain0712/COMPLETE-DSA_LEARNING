class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currmax=0;
        int maxsum=0;
        int currmin=0;
        int minsum=0;
        for(int i=0;i<nums.size();i++)
        {
            currmax+=nums[i];
            if(currmax<0)
            {
                currmax=0;
            }
            maxsum=max(maxsum,currmax);

            currmin+=nums[i];
            if(currmin>0)
            {
                currmin=0;
            }
            minsum=min(minsum,currmin);
        }
        return max(maxsum,abs(minsum));
    }
};