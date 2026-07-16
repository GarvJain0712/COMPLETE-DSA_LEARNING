class Solution {
public:
    static bool cmp(vector<int> &a , vector<int> &b)
    {
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
         if (pairs.empty())
            return 0;
        int count =1;
       
        sort(pairs.begin(),pairs.end(),cmp);
         int currend=pairs[0][1];
         
        for(int i=1;i<pairs.size();i++)
        {
            if(pairs[i][0]>currend)
            {
                count++;
                currend=pairs[i][1];
            }
        }

        return count;
    }
};