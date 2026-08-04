class Solution {
public:
    int maxProduct(int n) {
        vector<int > digits;

        while(n>0)
        {
            int r=n%10;
            digits.push_back(r);
            n=n/10;
        }
        int m = digits.size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {

                int p=digits[i]*digits[j];
                ans=max(p,ans);
            }
        }
        return ans;
    }
};