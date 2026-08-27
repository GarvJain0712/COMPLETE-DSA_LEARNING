class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        unordered_map<char, int > mp;
string ans="";

        for(char ch : s)
        {
            mp[ch]++;
        }

        for(int i=0;i<target.size();i++)
        {
            char c= target[i];
            
            if(mp[c]>0)
            {
                ans+=c;
                mp[c]--;
            }
            else
            {
                char bigger='(';
                for(char ch=c+1;ch<='z';ch++)
                {
                    if(mp[ch]>0)
                    {
                        bigger=ch;
                        break;
                    }
                }
                if(bigger!='(')
                {
                    ans+=bigger;
                    mp[bigger]--;

                    for(char ch ='a';ch<='z';ch++)
                    {
                        while(mp[ch]>0)
                        {
                            ans+=ch;
                            mp[ch]--;

                        }
                    }

                    return ans;
                }
                 break;
            }
           
        }

         // Backtracking
        for(int i = ans.size() - 1; i >= 0; i--) {

            mp[ans[i]]++;

            char c = target[i];

            // Find smallest character > target[i]
            for(char x = c + 1; x <= 'z'; x++) {

                if(mp[x] > 0) {

                    string res = ans.substr(0, i);

                    res += x;
                    mp[x]--;

                    // Add remaining characters
                    for(char y = 'a'; y <= 'z'; y++) {
                        while(mp[y] > 0) {
                            res += y;
                            mp[y]--;
                        }
                    }

                    return res;
                }
            }
        }
        return "";
    }
};