class Solution {
public:
    bool check(vector<int>& nums1, int target)
    {
        bool seenodd = false;

        for(int x : nums1)
        {
            if(x % 2 != target)
            {
                if(!seenodd)
                    return false;
            }
            if(x % 2 == 1)
                seenodd = true;
        }

        return true;
    }

    bool uniformArray(vector<int>& nums1)
    {
        sort(nums1.begin(), nums1.end());

        return check(nums1, 0) || check(nums1, 1);
    }
};