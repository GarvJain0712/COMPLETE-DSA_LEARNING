class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char > st;

        for(char digit : num)
        {
            while(!st.empty() && st.top()>digit && k>0)
            {
                st.pop();
                k--;

            }
            st.push(digit);
        }
        // case where num in sccending order 
                while(k > 0)
            {
                st.pop();
                k--;
            }
        string ans ="";

        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        int n =ans.size();
            int i=0;
            while(i<n && ans[i]=='0')
            {
                i++;
            }

            ans=ans.substr(i);
              if (ans.empty())
            return "0";

        return ans;
    }
};