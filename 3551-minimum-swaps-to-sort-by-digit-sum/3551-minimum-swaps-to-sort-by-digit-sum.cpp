
class Solution {
public:
    int getdigitsum(int n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> afterSorted(nums);

        auto lambda = [&](int n1, int n2) {
            int sum1 = getdigitsum(n1);
            int sum2 = getdigitsum(n2);

            if (sum1 != sum2)
                return sum1 < sum2;

            return n1 < n2;
        };

        sort(afterSorted.begin(), afterSorted.end(), lambda);

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int expectedval = afterSorted[i];
            int currval = nums[i];

            if (expectedval == currval)
                continue;

            int idx = mp[expectedval];

            nums[i] = expectedval;
            nums[idx] = currval;

            mp[expectedval] = i;
            mp[currval] = idx;

            swaps++;
        }

        return swaps;
    }
};
