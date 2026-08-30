class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=-1;
        int maxi=-1;
        int maxnum=INT_MIN;
        int minnum=INT_MAX;
        int n=nums.size();

        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            if(num<minnum)
            {
                mini=i;
                minnum=num;
            }
            if(num>maxnum)
            {
                maxi=i;
                maxnum=num;
            }
        }

        int left=min(mini,maxi);
        int right=max(mini,maxi);

        int fromfront=right+1;
        int fromback=n-left;

        int mixed= (left+1) +(n-right);

        return min({fromfront,fromback,mixed});
    }
};