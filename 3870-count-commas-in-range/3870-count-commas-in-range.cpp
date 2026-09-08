class Solution {
public:
    long long countCommas(int n) {
        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            int digits = to_string(i).length();

            ans += (digits - 1) / 3;
        }

        return ans;
    }
};