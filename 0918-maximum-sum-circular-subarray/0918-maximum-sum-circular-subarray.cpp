class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0;

        // Maximum Kadane
        int currsum = 0;
        int maxsum = INT_MIN;

        // Minimum Kadane
        int currmin = 0;
        int minsum = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {

            total += nums[i];

            // Maximum subarray
            currsum += nums[i];
            maxsum = max(maxsum, currsum);
            if (currsum < 0)
                currsum = 0;

            // Minimum subarray
            currmin += nums[i];
            minsum = min(minsum, currmin);
            if (currmin > 0)
                currmin = 0;
        }

        // All elements are negative
        if (maxsum < 0)
            return maxsum;

        return max(maxsum, total - minsum);
    }
};