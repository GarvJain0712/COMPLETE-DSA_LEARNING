class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
      unordered_map<int , int > mp;
        int n=nums.size();
      for(int i=0;i<=n-k;i++)
      {
        unordered_set<int> s;

        for(int j=i;j<k+i;j++)
        {
            s.insert(nums[j]);
        }

        for(int ele : s)
        {
            mp[ele]++;
        }
      }

      int ans=-1;

      for(auto x : mp)
      {
        if(x.second ==1)
        {
            ans=max(ans,x.first);
        }
      }

      return ans;
    }
};