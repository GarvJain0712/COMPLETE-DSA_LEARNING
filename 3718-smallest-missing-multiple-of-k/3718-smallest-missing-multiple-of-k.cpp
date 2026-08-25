class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int x =1;

        while(1)
        {
            int num=k*x;
            int found=0;
        for(int i=0;i<nums.size();i++)
        {
            if(num==nums[i])
            {
                found=1;
            }
        }
        if(!found)
        {
            return num;
        }
        x++;
        }
    }
};