class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                ones.push_back(i);
            }
        }
string ans="";

        for(int i=0;i+k-1<ones.size();i++)
        {
            int start=ones[i];
            int end=ones[i+k-1];

            string candi=s.substr(start,end-start+1);

            

            if(ans=="")
            {
                ans=candi;
            }
            else if(candi.length()<ans.length())
            {
                ans=candi;
            }
            else if(candi.length()==ans.length() && candi<ans)
            {
                ans=candi;
            }
        }

        return ans;
    }
};