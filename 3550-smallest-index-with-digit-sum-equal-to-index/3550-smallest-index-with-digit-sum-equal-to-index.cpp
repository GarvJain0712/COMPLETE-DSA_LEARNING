class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n =nums.size();
        int ans =-1;
        for(int i=0;i<n;i++)
        {
            int x = nums[i];
            int sum=0;
            while(x)
            {
                int r=x%10;
                sum+=r;

                x=x/10;
            }

            if( sum==i)
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};