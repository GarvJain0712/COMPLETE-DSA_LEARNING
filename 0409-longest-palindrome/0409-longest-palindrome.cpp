class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;

        for(char ch : s)
        {
            mp[ch]++;
        }

        bool odd =false;
        int ans =0;
        for(auto it : mp)
        {
            if(it.second%2==0)
            {
                ans=ans + it.second;
            }
            else
            {
                odd=true;
                ans=ans+it.second-1;
            }
        }

        if(odd)
        {
            ans++;
        }
        return ans;
    }
};