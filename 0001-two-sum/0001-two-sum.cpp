class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int > ans ;
        int n=nums.size();
       unordered_map<int ,int > m;

       for(int i=0;i<n;i++)
       {
        int comple = target-nums[i];
        if(m.count(comple))
        {
            ans.push_back(i);
            ans.push_back(m[comple]);
        }
        m[nums[i]]=i;
       }
        return ans;
    }

};