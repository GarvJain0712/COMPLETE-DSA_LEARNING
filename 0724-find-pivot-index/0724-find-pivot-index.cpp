class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int > prefixL(nums.size(),0);
        vector<int > prefixR(nums.size(),0); 
        int n =nums.size();

        
        
        for(int i=0;i<n-1;i++)
        {
            prefixL[i+1]=prefixL[i]+nums[i];
        }

        for(int i=n-2;i>=0;i--)
        {
            prefixR[i]=nums[i+1]+prefixR[i+1];
        }

        for(int i=0;i<n;i++)
        {
        if(prefixR[i]==prefixL[i])
        {
            return i;
        }
        }
       

        return -1;
    }
};