class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n =nums.size();
        int total=0;

        for(int i : nums)
        {
            total+=i;
        }


        int find=total-x;
         if( find <0)
        {
            return -1;
        }

        if(find==0)
        {
            return n;
        }
        int left=0;
        int currsum=0;
        int maxlen=-1;
        for(int right =0;right<n ;right++)
        {
            currsum+=nums[right];

            while (left <= right && currsum > find) {
                currsum -= nums[left];
                left++;
            }


            if(currsum==find)
            {
                maxlen=max(maxlen,right-left+1);
            }
        }
if( maxlen==-1)
{
    return -1;
}
return n-maxlen;
    }
};