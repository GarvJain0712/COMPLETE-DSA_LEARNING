class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int min1=INT_MAX;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[high])
            {
                min1=min(min1,nums[low]);
                break;
            }
            if(nums[low]<=nums[mid])   // left line 
            {
                min1 =min(min1,nums[low]);
                low=mid+1;
            }
            else        // right line 
            {
                min1=min(min1,nums[mid]);
                high=mid-1;
            }
        }
        return min1;
    }
};