class Solution {
public:
    typedef long long ll;

    string freeSlotsFiller(ll required, int length) {
        string str;
        for (int digit = 9; digit >= 2; digit--) {
            while (required % digit == 0) {
                str.push_back(char(digit + '0'));
                required /= digit;
            }
        }
        while ((int)str.length() < length) {
            str.push_back('1');
        }
        reverse(begin(str), end(str));
        return str;
    }

    string smallestNumber(string num, ll t) {
        int n = num.length();

        ll temp = t;
        for (int primeFact : {2, 3, 5, 7}) {
            while (temp % primeFact == 0) temp /= primeFact;
        }
        if (temp != 1) return "-1";

        vector<ll> remainingFactor(n + 1, t);
        int zeroPos = num.find('0');
        int zeroIdx = n - 1;
        if (zeroPos != -1) zeroIdx = zeroPos;

        for (int i = 0; i < (zeroPos != -1 ? zeroIdx : n); i++) {
            int digit = num[i] - '0';
            remainingFactor[i+1] = remainingFactor[i] / __gcd(remainingFactor[i], (ll)digit);
        }

        // num itself already works
        if (zeroPos == -1 && remainingFactor[n] == 1) return num;

        for (int i = zeroIdx; i >= 0; i--) {
            ll required = remainingFactor[i];
            int freeSlots = n - 1 - i;

            for (int digit = (num[i] - '0') + 1; digit <= 9; digit++) {
                ll furtherRequired = required / __gcd(required, (ll)digit);
                string requiredNumber = freeSlotsFiller(furtherRequired, freeSlots);

                if ((int)requiredNumber.length() == freeSlots) {
                    return num.substr(0, i) + char('0' + digit) + requiredNumber;
                }
            }
        }

        int L = n + 1;
        string ans = freeSlotsFiller(t, L);
        while ((int)ans.length() != L) {
            L++;
            ans = freeSlotsFiller(t, L);
        }
        return ans;
    }
};