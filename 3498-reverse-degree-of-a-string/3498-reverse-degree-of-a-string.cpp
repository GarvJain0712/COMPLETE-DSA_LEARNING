class Solution {
public:
    int reverseDegree(string s) {
        int ans =0;

        for(int i=0;i<s.size();i++)
        {
            int ch = 'z'-s[i]+1;
            int x=ch*(i+1);
            ans +=x;
        }

        return ans;
    }
};