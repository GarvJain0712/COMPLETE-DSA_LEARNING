class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        string ans ="";
         unordered_map<string, string> mp;

    
        for (auto &pair : knowledge) {
            mp[pair[0]] = pair[1];
        }
        for (int i=0;i<n ;)
        {
            if( s[i]!='(')
            {
                ans +=s[i];
                i++;
            }
            else
            {
                int j=i+1;

                while(s[j]!=')')
                {
                    j++;
                }

                string sub= s.substr(i+1,j-i-1);

                
                if (mp.find(sub) != mp.end()) {
                    ans += mp[sub];
                }
                else {
                    ans += "?";
                }
                i=j+1;
            }


        }
        return ans;
    }
};