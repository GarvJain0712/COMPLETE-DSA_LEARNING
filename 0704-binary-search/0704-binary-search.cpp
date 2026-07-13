class Solution {
public:
int cal(vector<int> nums,int st, int end, int target)
{
    int mid =st+(end-st)/2;
    if(st>end)
    {
        return -1;
    }
    if(target==nums[mid])
    {
        return mid;
    }
    else if(target<nums[mid])
    {
        return cal(nums,st,mid-1,target);
    }
    else
    {
        return cal(nums,mid+1,end,target);
    }
    
}
    int search(vector<int>& nums, int target) {
        int idx =cal(nums,0,nums.size()-1,target);
        return idx;
    }
};