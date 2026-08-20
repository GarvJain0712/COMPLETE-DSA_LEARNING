class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int left=0;
        unordered_map<char , int > mp;
        int n = s.size();
        int ans =0;

        for(int i=0;i<n;i++)
        {   
            char ch=s[i];
            mp[ch]++;

            while(mp[ch]>2)
            {
                mp[s[left]]--;
                left++;
            }

            ans =max(ans , i-left+1);
        }

        return ans ;
    }
};