class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<bool>used(n,false);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int f=fruits[i];
            bool placed=false;
            for(int j=0;j<n;j++)
            {   
                if(!used[j] && baskets[j]>=f)
                {
                    used[j]=true;
                    placed=true;
                    break;
                }
            }
            if(!placed)
                {
                    ans++;
                }
        }
        return ans;
    }
};